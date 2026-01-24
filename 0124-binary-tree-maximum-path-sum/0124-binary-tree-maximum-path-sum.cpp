class Solution {
public:
    int ans = INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int leftSum = helper(root->left), rightSum = helper(root->right);
        ans = max({ans, root->val, root->val + leftSum, root->val + rightSum, root->val + leftSum + rightSum});
        return root->val = max(root->val, root->val + max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};