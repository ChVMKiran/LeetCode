class Solution {
public:
    int helper(TreeNode* root) {
        if(!root) return 0;
        int lh = helper(root->left), rh = helper(root->right);
        if(lh == -1 || rh == - 1 || abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};