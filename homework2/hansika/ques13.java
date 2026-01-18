/*
Technique Used: Level-order (breadth-first) traversal
Time Complexity: O(n)      // visit every node once
Space Complexity: O(n)     // queue used for BFS

Time spent:25min
*/
import java.util.*;
class TreeNode 
{
    int val;
    TreeNode left, right;
    TreeNode(int v) { this.val = v; }
}

public class ques13 
{
    // Left view using BFS
    public static List<Integer> leftView(TreeNode root) 
    {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty())
         {
            int size = q.size();
            // first node in this level
            result.add(q.peek().val);
            // process children of this level
            while (size-- > 0) 
            {
                TreeNode node = q.poll();
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return result;
    }


    public static void main(String[] args) 
    {

        // eg1
        TreeNode a = new TreeNode(7);
        a.left = new TreeNode(8);
        a.right = new TreeNode(3);
        a.right.left = new TreeNode(9);
        a.right.right = new TreeNode(13);
        a.right.left.left = new TreeNode(20);
        a.right.left.right = new TreeNode(14);
        a.right.left.right.right = new TreeNode(15);
        System.out.println("Example 1 Output: " + leftView(a));
        // Expected: [7, 8, 9, 20, 15]
        //eg2
        TreeNode b = new TreeNode(7);
        b.left = new TreeNode(20);
        b.right = new TreeNode(4);
        b.left.left = new TreeNode(15);
        b.left.right = new TreeNode(6);
        b.right.left = new TreeNode(8);
        b.right.right = new TreeNode(11);
        System.out.println("Example 2 Output: " + leftView(b));
        // Expected: [7, 20, 15]
    }
}
