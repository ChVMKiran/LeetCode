class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1, time = 1;
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++) {
            if(vis[i] != -1) continue;
            int j = i, st = time;
            while(j != -1 && vis[j] == -1) {
                vis[j] = time++;
                j = edges[j];
            }
            if(j != -1 && vis[j] >= st) {
                ans = max(ans, time - vis[j]);
            }
        }
        return ans;
    }
};