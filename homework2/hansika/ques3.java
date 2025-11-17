//bst
public class ques3 
{
    static class Node 
    {
        int data;
        Node left;
        Node right;
        Node(int d) 
        { 
            data = d; left = right = null; 
        }
    }
    private Node root;
    // returns the minimum value in the BST 
    // O(h) time (h = tree height)
    public int min() 
    {
        if (root == null) throw new IllegalStateException("Tree is empty");
        Node cur = root;
        while (cur.left != null) cur = cur.left;
        return cur.data;
    }
    // returns the maximum value in the BST. O(h) time
    public int max() 
    {
        if (root == null) throw new IllegalStateException("Tree is empty");
        Node cur = root;
        while (cur.right != null) cur = cur.right;
        return cur.data;
    }
    // returns true if val is present in BST. O(h) time
    public boolean contains(int val) 
    {
        Node cur = root;
        while (cur != null) 
        {
            if (val == cur.data) return true;
            else if (val < cur.data) cur = cur.left;
            else cur = cur.right;
        }
        return false;
    }
    // inserts val into BST. If val already present, do nothing. O(h) time
    public void insert(int val) 
    {
        if (root == null) 
        {
            root = new Node(val);
            return;
        }
        Node cur = root;
        Node parent = null;
        while (cur != null) 
        {
            parent = cur;
            if (val == cur.data) 
            {
                return;
            } 
            else if (val < cur.data) 
            {
                cur = cur.left;
            } 
            else 
            {
                cur = cur.right;
            }
        }
        if (val < parent.data) parent.left = new Node(val);
        else parent.right = new Node(val);
    }

    // deletes the node with data val if it exists. O(h) time
    public void delete(int val) 
    {
        root = deleteRec(root, val);
    }
    // helper: returns new subtree root after deletion
    private Node deleteRec(Node node, int val) 
    {
        if (node == null) return null;
        if (val < node.data) 
        {
            node.left = deleteRec(node.left, val);
        } 
        else if (val > node.data) 
        {
            node.right = deleteRec(node.right, val);
        } 
        else 
        {
            // case 1: no child
            if (node.left == null && node.right == null) 
            {
                return null;
            }
            // case 2: only right child
            if (node.left == null) 
            {
                return node.right;
            }
            // case 3: only left child
            if (node.right == null) 
            {
                return node.left;
            }
            // case 4: two children, replace with inorder successor (min in right subtree)
            Node succ = node.right;
            while (succ.left != null) succ = succ.left;
            node.data = succ.data;
            node.right = deleteRec(node.right, succ.data);
        }
        return node;
    }
}
