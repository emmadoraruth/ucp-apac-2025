package homework2.Saytam_Mishra;
// Technique - Search binary search tree (BST)
// Time Complexity - O(n) in worst case and O(logn) in average case
// Space Complexity - O(1)

public class q14_floorInBST {
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

    public static int floor(TreeNode root, int target) {
        TreeNode current = root;

        int ans = 0;
        boolean ifFound = false;
        while (current != null) {
            if (current.val <= target) {
                ifFound = true;
                ans = current.val;
                current = current.right;
            } else {
                current = current.left;
            }
        }

        return ifFound ? ans : -1;
    }

    public static void main(String[] args) {
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(8);
        root1.right = new TreeNode(16);
        root1.left.right = new TreeNode(9);
        root1.right.left = new TreeNode(13);
        root1.right.right = new TreeNode(17);
        root1.right.right.right = new TreeNode(20);

        // Test Case 1

        int target1 = 13;
        int res1 = floor(root1, target1);
        System.out.println("Greatest element less than or equal to 13 is: " + (res1 != -1 ? res1 : "No element found"));

        // Test Case 2

        int target2 = 15;

        int res2 = floor(root1, target2);
        System.out.println("Greatest element less than or equal to 13 is: " + (res2 != -1 ? res2 : "No element found"));
    }
}

// Time spent - 9m 10s