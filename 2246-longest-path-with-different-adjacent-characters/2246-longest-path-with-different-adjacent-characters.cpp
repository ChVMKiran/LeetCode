class Solution {
public:
    int ans;
    vector<int> childs[100001];
    int dfs(string &s, int ind) {
        int val1 = 0, val2 = 0;
        for(auto& c: childs[ind]) {
            int val = dfs(s, c);
            ans = max(ans, val);
            if(s[c] != s[ind]) {
                if(val1 < val) {
                    val2 = val1;
                    val1 = val;
                }
                else if(val2 < val) val2 = val;
            }
        }
        ans = max(ans, val1 + val2 + 1);
        return 1 + val1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        ans = 1;
        for(int i = 1; i < n; i++) {
            childs[parent[i]].push_back(i);
        }
        dfs(s, 0);
        return ans;
    }
};