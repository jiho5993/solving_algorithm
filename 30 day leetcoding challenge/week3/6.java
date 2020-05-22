class Solution {
    public TreeNode bstFromPreorder(int[] preorder) {
        if(preorder == null || preorder.length == 0) {
            return null;
        }

        return dfs(preorder, 0, preorder.length - 1);
    }

    private TreeNode dfs(int[] preorder, int l, int r) {
        if(l > r) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[l]);
        int biggerIndex = l + 1;
        while(biggerIndex <= r && preorder[biggerIndex] < preorder[l]) {
            biggerIndex++;
        }

        root.left = dfs(preorder, l+1, biggerIndex-1);
        root.right = dfs(preorder, biggerIndex, r);
        return root;
    }
}