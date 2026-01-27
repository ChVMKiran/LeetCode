class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        vector<int> vec(n, INT_MAX);
        vec[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, e] = pq.top();
            pq.pop();
            if(vec[e] < d) continue;
            if(e == n - 1) return d;
            for(auto &[nn, w] : adj[e]) {
                if(vec[nn] > d + w) {
                    vec[nn] = d + w;
                    pq.push({d + w, nn});
                }
            }
        }
        return vec[n - 1] == INT_MAX ? -1 : vec[n - 1];
    }
};