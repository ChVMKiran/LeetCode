class Solution {
private:
    int getHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(getHeight(root -> left), getHeight(root->right));
    }

    TreeNode* answer(TreeNode* root, int currDepth, int maxDepth) {
        if(!root || currDepth == maxDepth) return root;
        TreeNode* left = answer(root -> left, currDepth + 1, maxDepth);
        TreeNode* right = answer(root -> right, currDepth + 1, maxDepth);
        if(left && right) return root;
        return left ? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = getHeight(root);
        return answer(root, 1, maxDepth);
    }
};