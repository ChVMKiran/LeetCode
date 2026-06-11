class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1, mod = 1e9 + 7, maxi = 1;
        long ans = 1;
        vector<vector<int>> adj(n + 1);
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n + 1);
        queue<pair<int, int>> qu;
        qu.push({1, 0});
        vis[1] = 1;
        while(!qu.empty()) {
            auto [node, height] = qu.front();
            // cout<<node<<' '<<height<<endl;
            if(maxi < height) {
                ans <<= 1;
                ans %= mod;
                maxi = height;
            }
            qu.pop();
            for(int& nn: adj[node]) {
                if(!vis[nn]) {
                    vis[nn] = 1;
                    qu.push({nn, height + 1});
                }
            }
        }
        return ans;
    }
};