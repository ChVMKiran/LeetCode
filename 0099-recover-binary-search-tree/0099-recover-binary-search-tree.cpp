class Solution {
public:
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void helper(TreeNode* root) {
        if(!root) return;
        helper(root -> left);
        if(!first && prev -> val > root -> val) {
            first = prev;
            second = root;
        }
        else if(first && prev -> val > root -> val) {
            second = root;
        }
        prev = root;
        helper(root -> right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first -> val, second -> val);
    }
};