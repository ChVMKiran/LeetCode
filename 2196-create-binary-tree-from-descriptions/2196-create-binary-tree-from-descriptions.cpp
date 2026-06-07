class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root;
        unordered_map<int, TreeNode*> ump;
        unordered_map<int, int> parent;
        for(auto& d: descriptions) {
            if(!ump.count(d[0])) ump[d[0]] = new TreeNode(d[0]);
            if(!ump.count(d[1])) ump[d[1]] = new TreeNode(d[1]);
            if(d[2]) ump[d[0]]->left = ump[d[1]];
            else ump[d[0]]->right = ump[d[1]];
            parent[d[1]] = d[0];
            root = ump[d[0]];
        }
        while(parent.count(root->val)) root = ump[parent[root->val]];
        return root;
    }
};