class Solution {
private:
    unordered_map<int, int> ump;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pst, int pend, int ist, int iend) {
        if(ist > iend || pst > pend) return NULL;
        TreeNode* curr = new TreeNode(preorder[pst]);
        int left = ump[preorder[pst]] - ist;
        curr -> left = helper(preorder, inorder, pst + 1, pst + left, ist, ist + left - 1);
        curr -> right = helper(preorder, inorder, pst + left + 1, pend, ist + left + 1, iend);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) ump[inorder[i]] = i;
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};