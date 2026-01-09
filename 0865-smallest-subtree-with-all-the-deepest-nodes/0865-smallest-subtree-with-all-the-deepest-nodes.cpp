class Solution {
    int getDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(getDepth(root -> left), getDepth(root -> right));
    }

    TreeNode* helper(TreeNode* root, int currDepth, int maxDepth) {
        if(!root || currDepth == maxDepth) return root;
        TreeNode* left = helper(root -> left, currDepth + 1, maxDepth);
        TreeNode* right = helper(root -> right, currDepth + 1, maxDepth);
        if(left && right) return root;
        return left ? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = getDepth(root);
        return helper(root, 1, maxDepth);
    }
};