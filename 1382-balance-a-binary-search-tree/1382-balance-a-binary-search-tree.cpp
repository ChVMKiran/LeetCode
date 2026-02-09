class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec) {
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    TreeNode* formAVL(vector<int>& vec, int l, int h) {
        if(l > h) return nullptr;
        int m = l + (h - l) / 2;
        TreeNode* curr = new TreeNode(vec[m]);
        curr->left = formAVL(vec, l, m - 1);
        curr->right = formAVL(vec, m + 1, h);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return formAVL(vec, 0, vec.size() - 1);
    }
};