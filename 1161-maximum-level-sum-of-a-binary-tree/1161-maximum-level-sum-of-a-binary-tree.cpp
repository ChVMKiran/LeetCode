class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxi = root->val, level = 1;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            int len = qu.size(), curr = 0;
            while(len--) {
                auto& ptr = qu.front();
                curr += ptr->val;
                if(ptr->left) qu.push(ptr->left);
                if(ptr->right) qu.push(ptr->right);
                qu.pop();
            }
            if(maxi < curr) {
                maxi = max(maxi, curr);
                ans = level;
            }
            level++;
        }
        return ans;
    }
};