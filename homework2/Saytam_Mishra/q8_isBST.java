package homework2.Saytam_Mishra;
// Depth-first traversal (Pre-order)
// Time Complexity - O(n)
// Space Complexity - O(n), O(logn) for perfectly balanced tree

public class q8_isBST {
    static class TreeNode {
        TreeNode left;
        TreeNode right;
        int val;

        public TreeNode(int val) {
            this.left = null;
            this.right = null;
            this.val = val;
        }
    }

    public static boolean isBST(TreeNode root, Integer min, Integer max) {
        if(root == null) return true;

        if(min != null && min >= root.val) {
            return false;
        }
        if(max != null && max <= root.val) {
            return false;
        }

        return isBST(root.left, min, root.val) && isBST(root.right, root.val, max);
    }

    public static void main(String[] args) {
        // Test Case 1
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(8);
        root1.right = new TreeNode(16);
        root1.left.right = new TreeNode(9);
        root1.right.left = new TreeNode(13);
        root1.right.right = new TreeNode(17);
        root1.right.right.right = new TreeNode(20);
        System.out.println("Is Tree 1 a BST: " + isBST(root1, null, null));

        // Test Case 2
        TreeNode root2 = new TreeNode(10);
        root2.left = new TreeNode(8);
        root2.right = new TreeNode(16);
        root2.left.right = new TreeNode(9);
        root2.right.left = new TreeNode(13);
        root2.right.right = new TreeNode(17);
        root2.right.right.right = new TreeNode(15);
        System.out.println("Is Tree 2 a BST: " + isBST(root2, null, null));
    }
}

// Time spent - 25m 34s