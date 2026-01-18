package homework2.Saytam_Mishra;
// Technique - Level-order (breadth-first) traversal
// Time Complexity - O(n)
// Space Complexity - O(w) average where w is maximum width of tree, O(n) in worst case and O(1) in best case

import java.util.Queue;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

public class q13_leftView {
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

    public static List<Integer> leftView(TreeNode root) {
        if(root == null) return new ArrayList<>();

        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        List<Integer> leftMostElements = new ArrayList<>();

        while (!q.isEmpty()) {
            int size = q.size();
            leftMostElements.add(q.peek().val);

            for(int i = 0; i < size; i++) {
                TreeNode front = q.poll();
                if(front.left != null) q.add(front.left);
                if(front.right != null) q.add(front.right);
            }
        }

        return leftMostElements;
    }
    public static void main(String[] args) {
        // Test Case 1
        TreeNode root1 = new TreeNode(7);
        root1.left = new TreeNode(8);
        root1.right = new TreeNode(3);
        root1.right.left = new TreeNode(9);
        root1.right.right = new TreeNode(13);
        root1.right.left.left = new TreeNode(20);
        root1.right.right.left = new TreeNode(14);
        root1.right.right.left.right = new TreeNode(15);
        
        System.out.println("Left view of Tree 1 is: " + leftView(root1));

        System.out.println("----------------------------------------");

        // Test Case 2
        TreeNode root2 = new TreeNode(7);
        root2.left = new TreeNode(20);
        root2.right = new TreeNode(4);
        root2.left.left = new TreeNode(15);
        root2.left.right = new TreeNode(6);
        root2.right.left = new TreeNode(8);
        root2.right.right = new TreeNode(11);
        
        System.out.println("Left view of Tree 2 is: " + leftView(root2));
    }
}

// Time spent - 13m 33s