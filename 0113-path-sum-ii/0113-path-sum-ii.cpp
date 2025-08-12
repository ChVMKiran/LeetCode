class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& curr, TreeNode* root,
             int target) {
        if (!root->left && !root->right) {
            if (target == root->val) {
                curr.push_back(root->val);
                ans.push_back(curr);
                curr.pop_back();
            }
            return;
        }
        curr.push_back(root -> val);
        if(root -> left) fun(ans, curr, root -> left, target - root -> val);
        if(root -> right) fun(ans, curr, root -> right, target - root -> val);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> curr;
        fun(ans, curr, root, targetSum);
        return ans;
    }
};