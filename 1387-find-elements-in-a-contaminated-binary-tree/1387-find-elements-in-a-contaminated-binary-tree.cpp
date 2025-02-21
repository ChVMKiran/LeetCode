class FindElements {
private:
    TreeNode* root;
    unordered_set<int>ust;
    void dfs(TreeNode* root, int val){
        if(!root)return;
        root->val = val;
        ust.insert(val);
        dfs(root->left,val*2+1);
        dfs(root->right,val*2+2);
    }
    
public:
    FindElements(TreeNode* root) {
        this->root = root;
        dfs(root,0);
    }
    
    bool find(int target) {
        return ust.find(target)!=ust.end();
    }
};
