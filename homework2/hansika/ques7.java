/*
Technique Used: Tree Traversal - Pre-order (DFS)
Time Complexity: O(n)  // visiting each node once
Space Complexity: O(h) // recursion stack, h = height of tree

Time spent: 14 min
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

public class ques7 
{
    public static TreeNode copyTree(TreeNode root) 
    {
        if (root == null) return null;
        TreeNode newRoot = new TreeNode(root.val);
        newRoot.left = copyTree(root.left);
        newRoot.right = copyTree(root.right);
        return newRoot;
    }

    // Test Code
    public static void main(String[] args) 
    {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(8);
        root.right = new TreeNode(16);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(17);
        TreeNode copied = copyTree(root);
        System.out.println("Original root: " + root.val);
        System.out.println("Copied root: " + copied.val);
        System.out.println("Different objects? " + (root != copied));
    }
}
