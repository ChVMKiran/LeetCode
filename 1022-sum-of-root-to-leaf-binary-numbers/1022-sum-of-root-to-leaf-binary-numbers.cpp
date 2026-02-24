class Solution {
public:
    int helper(TreeNode* root, int curr) {
        if(!root) return 0;
        curr <<= 1;
        if(root->val) curr ^= 1;
        if(!root->left && !root->right) return curr;
        int res = 0;
        if(root->left) res += helper(root->left, curr);
        if(root->right) res += helper(root->right, curr);
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};