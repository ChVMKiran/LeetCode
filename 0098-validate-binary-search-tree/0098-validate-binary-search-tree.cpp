class Solution {
public:
    int lastMax = INT_MIN;
    bool flag = false;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = isValidBST(root->left);
        if(flag && root->val <= lastMax) return false;
        lastMax = root->val;
        flag = true;
        bool right = isValidBST(root->right);
        return left && right;
    }
};