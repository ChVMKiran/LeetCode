class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        long long time = INT_MAX, cnt = 0, mod = 1e9 + 7;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if(cost != dist[node]) continue;
            if(node == n - 1) continue;
            for(auto& [nn, w]: adj[node]) {
                if(dist[nn] > cost + w) {
                    dist[nn] = cost + w;
                    ways[nn] = ways[node];
                    pq.push({dist[nn], nn});
                }
                else if(dist[nn] == cost + w) {
                    ways[nn] = (ways[nn] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};