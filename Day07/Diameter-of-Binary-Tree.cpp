struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int ans = 0;
int dfs(TreeNode* root){
    if(!root) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    ans = max(ans, l + r);
    return max(l, r) + 1;
}
