class Solution {
private:
    long long ans = 0, tsum = 0, mod = 1e9 + 7;
    void totalSum(TreeNode* root) {
        if(!root) return;
        tsum += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }
    long long helper(TreeNode* root) {
        if(!root) return 0;
        long long left = helper(root->left);
        ans = max(ans, (left * (tsum - left)));
        long long right = helper(root->right);
        ans = max(ans, right * (tsum - right));
        return left + right + root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum(root);
        helper(root);
        return ans % mod;
    }
};