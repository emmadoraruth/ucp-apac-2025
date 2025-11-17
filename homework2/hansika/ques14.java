/*
Technique Used: Search binary search tree (BST)
Time Complexity: O(h)       // h = height of tree
Space Complexity: O(1)      
Time spent: 20minutes
*/

class TreeNode 
{
    int val;
    TreeNode left, right;
    TreeNode(int v) 
    { 
        this.val = v; 
    }
}
public class ques14 
{
    // Return floor value
    public static Integer floorInBST(TreeNode root, int target) 
    {
        Integer floor = null;
        while (root != null) 
        {
            if (root.val == target) 
            {
                return root.val;  // exact match is best possible floor
            }
            else if (root.val < target) 
            {
                floor = root.val; // potential floor
                root = root.right;
            }
            else 
            {
                root = root.left; // go to smaller values
            }
        }
        return floor;
    }


    public static void main(String[] args) 
    {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(8);
        root.right = new TreeNode(16);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(17);
        root.right.right.right = new TreeNode(20);
        // Example 1,target = 13
        System.out.println("Example 1 Output: " + floorInBST(root, 13));
        // Expected: 13
        // Example 2, target = 15
        System.out.println("Example 2 Output: " + floorInBST(root, 15));
        // Expected: 13
    }
}
