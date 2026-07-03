class Solution {
public:
    int n;
    bool helper(int limit, unordered_map<int, vector<pair<int,int>>>& adj, vector<bool>& online, long long k) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [c, node] = pq.top();
            pq.pop();
            if(dist[node] != c) continue;
            for(auto& [nn, w]: adj[node]) {
                if(dist[nn] < w + c || !online[nn] || w < limit) continue;
                dist[nn] = w + c;
                pq.push({dist[nn], nn});
            }
        }
        return dist[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        int l = INT_MAX, h = 0;
        for(auto& e: edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            l = min(l, c);
            h = max(h, c);
        }
        if(!helper(l, adj, online, k)) return -1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(helper(m, adj, online, k)) l = m + 1;
            else h = m - 1;
        }
        return h;
    }
};