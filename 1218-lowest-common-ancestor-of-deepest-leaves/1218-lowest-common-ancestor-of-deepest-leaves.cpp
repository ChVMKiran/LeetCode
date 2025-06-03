class Solution {
private:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    TreeNode* helper(TreeNode* root, int curr, int height) {
        if(!root || curr == height) return root;
        TreeNode* left = helper(root->left, curr + 1, height);
        TreeNode* right = helper(root->right, curr + 1, height);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = getHeight(root);
        return helper(root, 1, height);
    }
};