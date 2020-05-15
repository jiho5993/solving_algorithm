class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) {
            return 0;
        }

        int l = depth(root.left);
        int r = depth(root.right);
        int diameter = l + r;

        int dl = diameterOfBinaryTree(root.left);
        int dr = diameterOfBinaryTree(root.right);

        return Math.max(dl, Math.max(dr, diameter));
    }

    public int depth(TreeNode root) {
        if(root == null) {
            return 0;
        }

        int l = 1 + depth(root.left);
        int r = 1 + depth(root.right);

        return Math.max(l, r);
    }
}