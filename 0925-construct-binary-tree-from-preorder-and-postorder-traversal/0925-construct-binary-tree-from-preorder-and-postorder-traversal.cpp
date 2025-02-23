class Solution {
public:
    TreeNode* rec(unordered_map<int,int>&ump, vector<int>& preorder, int i1, int i2, vector<int>& postorder, int j1, int j2){
        if(i1>i2||j1>j2)return nullptr;
        TreeNode* root = new TreeNode(preorder[i1]);
        if(i1==i2)return root;
        int leftSize = ump[preorder[i1+1]]-j1+1;
        root->left = rec(ump,preorder,i1+1,i1+leftSize,postorder,j1,j1+leftSize-1);
        root->right = rec(ump,preorder,i1+1+leftSize,i2,postorder,j1+leftSize,j2-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>ump;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            ump[postorder[i]]=i;
        }
        return rec(ump,preorder,0,n-1,postorder,0,n-1);
    }
};