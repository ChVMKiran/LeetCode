class Solution {
private:
    unordered_map<int, int> ump;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ist, int iend, int pst, int pend) {
        if(ist > iend || pst > pend) return nullptr;
        TreeNode* curr = new TreeNode(postorder[pend]);
        int leftHeight = ump[postorder[pend]] - ist;
        curr->left = helper(inorder, postorder, ist, ist + leftHeight - 1, pst, pst + leftHeight - 1);
        curr->right = helper(inorder, postorder, ist + leftHeight + 1, iend, pst + leftHeight, pend - 1);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) ump[inorder[i]] = i;
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
