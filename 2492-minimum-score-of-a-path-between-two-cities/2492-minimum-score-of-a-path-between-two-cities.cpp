class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& road: roads) {
            adj[road[0] - 1].push_back({road[1] - 1, road[2]});
            adj[road[1] - 1].push_back({road[0] - 1, road[2]});
        }
        int ans = INT_MAX;
        queue<int> qu;
        vector<int> vis(n);
        qu.push(0);
        vis[0] = 1;
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for(auto& [nn, d]: adj[node]) {
                ans = min(ans, d);
                if(!vis[nn]) {
                    vis[nn] = 1;
                    qu.push(nn);
                }
            }
        }
        return ans;
    }
};