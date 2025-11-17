/*
Technique Used: Tree Traversal - In-order (DFS)
Time Complexity: O(n)
Space Complexity: O(h)
Time Spend: 22min
*/

class TreeNode 
{
    int val;
    TreeNode left, right;
    TreeNode(int val) 
    { 
        this.val = val; 
    }
}

public class ques8 
{
    static Integer prev = null;
    public static boolean isBST(TreeNode root) 
    {
        prev = null;
        return inorderCheck(root);
    }

    private static boolean inorderCheck(TreeNode node) 
    {
        if (node == null) return true;
        if (!inorderCheck(node.left)) return false;
        if (prev != null && node.val <= prev) return false;
        prev = node.val;
        return inorderCheck(node.right);
    }

    public static void main(String[] args) 
    {
        // eg1(true)
        TreeNode a = new TreeNode(10);
        a.left = new TreeNode(8);
        a.right = new TreeNode(16);
        a.left.right = new TreeNode(9);
        a.right.left = new TreeNode(13);
        a.right.right = new TreeNode(17);
        a.right.right.right = new TreeNode(20);

        System.out.println("Example 1 (true expected): " + isBST(a));

        //eg 2(false)
        TreeNode b = new TreeNode(10);
        b.left = new TreeNode(8);
        b.right = new TreeNode(16);
        b.left.right = new TreeNode(9);
        b.right.left = new TreeNode(13);
        b.right.right = new TreeNode(17);
        b.right.right.right = new TreeNode(15);  // violates BST

        System.out.println("Example 2 (false expected): " + isBST(b));
    }
}
