class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        // if(root->val == -54) {
        //     if(left == p) cout<<1;
        //     if(right == q) cout<<1;
        // }
        if(left == p && right == q) return root;
        else if(left == q && right == p) return root;
        else if(root == p && right == q) return root;
        else if(root == q && right == p) return root;
        else if(root == q && left == p) return root;
        else if(root == p && left == p) return root;
        if(left == p || right == p || root == p) return p;
        if(right == q || left == q || root == q) return q;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
};