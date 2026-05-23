class Solution {
    vector<vector<pair<int,int>>> adj;
    void dijkstra(vector<int>& dist, int st) {
        dist[st] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, st});
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if(dist[node] != cost) continue;
            for(auto& [nn, d]: adj[node]) {
                if(dist[nn] > cost + d) {
                    dist[nn] = cost + d;
                    pq.push({cost + d, nn});
                }
            }
        }
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> distSt(n, INT_MAX), distEnd(n, INT_MAX);
        adj.resize(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        dijkstra(distSt, 0);
        dijkstra(distEnd, n - 1);
        int m = edges.size(), minCost = distSt[n - 1];
        vector<bool> ans(m);
        for(int i = 0; i < m; i++) {
            int n1 = edges[i][0], n2 = edges[i][1], w = edges[i][2];
            if((long long)distSt[n1] + distEnd[n2] + w == minCost || (long long)distSt[n2] + distEnd[n1] + w == minCost) ans[i] = true;
        }
        return ans;
    }
};