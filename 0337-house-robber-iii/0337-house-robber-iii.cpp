class Solution {
public:
    unordered_map<TreeNode*, int> ump;
    int rob(TreeNode* root) { 
        if (!root || ump.count(root))
            return ump[root];
        int ans = root->val;
        if (root->left)
            ans += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            ans += rob(root->right->left) + rob(root->right->right);
        return ump[root] = max(ans, rob(root->left) + rob(root->right)); 
    }
};