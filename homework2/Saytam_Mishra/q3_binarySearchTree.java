package homework2.Saytam_Mishra;

class BinarySearchTree {
    class Node {
        int data;
        Node left;
        Node right;

        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    public int min() { // O(logn) in average case and O(n) in worst case
        if(root == null) {
            throw new IllegalStateException("Tree is empty");
        }

        Node current = root;

        while(current.left != null) {
            current = current.left;
        }

        return current.data;
    }

    public int max() { // O(logn) in average case and O(n) in worst case
        if(root == null) {
            throw new IllegalStateException("Tree is empty");
        }

        Node current = root;

        while(current.right != null) {
            current = current.right;
        }

        return current.data;
    }

    public boolean contains(int val) { // O(logn) in average case and O(n) in worst case
        Node current = root;

        while(current != null) {
            if(current.data > val) {
                current = current.left;
            } else if(current.data < val) {
                current = current.right;
            } else {
                return true;
            }
        }

        return false;
    }

    public void insert(int val) { // O(logn) in average case and O(n) in worst case
        Node newNode = new Node(val);

        if(root == null) {
            root = newNode;
            return;
        }

        Node current = root;
        Node parent = null;

        while(current != null) {
            parent = current;
            if(current.data > val) {
                current = current.left;
            } else if(current.data < val) {
                current = current.right;
            } else {
                return; // Node with data val already exists
            }
        }

        if(parent.data > val) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }
    }

    public void delete(int val) { // O(logn) in average case and O(n) in worst case
        if(root == null) return;

        if(root.data == val) {
            root = helper(root);
            return;
        }

        Node current = root;

        while (current != null) {
            if(current.data > val) {
                if (current.left != null && current.left.data == val) {
                    current.left = helper(current.left);
                    return;
                } else {
                    current = current.left;
                }
            } else {
                if (current.right != null && current.right.data == val) {
                    current.right = helper(current.right);
                    return;
                } else {
                    current = current.right;
                }
            } 
        }
    }

    public Node helper(Node root) {
        if(root.left == null) {
            return root.right;
        }

        if(root.right == null) {
            return root.left;
        }

        Node rightNode = root.right;

        Node rightMostNode = findRightMostNode(root.left);

        rightMostNode.right = rightNode;
        
        return root.left;
    }

    public Node findRightMostNode(Node root) {
        if(root.right == null) {
            return root;
        }

        return findRightMostNode(root.right);
    }

    public void printInOrder() {
        System.out.print("In-order: ");
        inOrderHelper(this.root);
        System.out.println();
    }

    private void inOrderHelper(Node node) {
        if (node == null) {
            return;
        }

        inOrderHelper(node.left);

        System.out.print(node.data + " ");

        inOrderHelper(node.right);
    }
}

public class q3_binarySearchTree {

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        bst.insert(20);
        bst.insert(10);
        bst.insert(30);
        
        bst.printInOrder();
    }
}

// Time taken - 36m 8s