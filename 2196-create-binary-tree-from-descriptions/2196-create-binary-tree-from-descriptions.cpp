class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int root = 0;
        unordered_map<int, TreeNode*> ump;
        for(auto& d: descriptions) {
            if(!ump.count(d[0])) {
                ump[d[0]] = new TreeNode(d[0]);
                root ^= d[0];
            }
            if(!ump.count(d[1])) {
                ump[d[1]] = new TreeNode(d[1]);
                root ^= d[1];
            }
            root ^= d[1];
            if(d[2]) ump[d[0]]->left = ump[d[1]];
            else ump[d[0]]->right = ump[d[1]];
        }
        return ump[root];
    }
};