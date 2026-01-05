bool isValid(TreeNode* root, long long minv, long long maxv){
    if(!root) return true;
    if(root->val <= minv || root->val >= maxv) return false;
    return isValid(root->left,minv,root->val) &&
           isValid(root->right,root->val,maxv);
}
