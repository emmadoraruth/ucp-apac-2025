package homework2.Saytam_Mishra;
// Depth-first traversal (Pre-order)
// Time Complexity - O(n)
// Space Complexity - O(n)

public class q7_copyTree {
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

    public static TreeNode deepCopy(TreeNode root) {
        if(root == null) return null;

        TreeNode newNode = new TreeNode(root.val);

        newNode.left = deepCopy(root.left);
        newNode.right = deepCopy(root.right);

        return newNode;
    }

    public static void printInOrder(TreeNode node) {
        if(node == null) return;

        printInOrder(node.left);
        System.out.print(node.val + " ");
        printInOrder(node.right);
    }

    public static void main(String[] args) {
        // Test Case - 1: Change a value in the NEW tree
        
        TreeNode root1 = new TreeNode(10);
        root1.left = new TreeNode(15);
        root1.right = new TreeNode(20);

        System.out.print("Original tree values (inorder): ");
        printInOrder(root1);
        System.out.println();

        TreeNode copiedRoot1 = deepCopy(root1);
        
        copiedRoot1.left.val = 99; // Change 15 to 99

        System.out.println("\n--- After changing copied tree's left child to 99 ---");
        System.out.print("Original tree values (in-order): ");
        printInOrder(root1);
        System.out.println();
        System.out.print("Copied tree values (in-order):   ");
        printInOrder(copiedRoot1);

        // Test Case - 2: Copy empty Tree
        System.out.println("\n------");
        TreeNode root2 = null;
        TreeNode copiedRoot2 = deepCopy(root2);
        System.out.println("Original root: " + root2);
        System.out.println("Copied root:   " + copiedRoot2);
    }
}

// Time spent - 23m 30s