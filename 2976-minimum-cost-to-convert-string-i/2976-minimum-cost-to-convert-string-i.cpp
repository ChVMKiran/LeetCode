class Solution {
public:
    vector<int> dijkstra(int src, vector<vector<pair<char, int>>>& adj) {
        vector<int> minCosts(26, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        minCosts[src] = 0;
        while(!pq.empty()) {
            auto [cost, ele] = pq.top();
            pq.pop();
            if(minCosts[ele] != -1 && minCosts[ele] < cost) continue;
            for(auto &[n, c] : adj[ele]) {
                if(minCosts[n - 'a'] == -1 || cost + c < minCosts[n - 'a']) {
                    minCosts[n - 'a'] = cost + c;
                    pq.push({cost + c, n - 'a'});
                }
            }
        }
        return minCosts;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m = source.size(), n = original.size();
        vector<vector<pair<char, int>>> adj(26);
        for(int i = 0; i < n; i++) {
            adj[original[i] - 'a'].push_back({changed[i], cost[i]});
        }
        vector<vector<int>> shortestPath(26, vector<int> (26));
        for(int i = 0; i < 26; i++) {
            shortestPath[i] = dijkstra(i, adj);
        }
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            if(source[i] != target[i]) {
                if(shortestPath[source[i] - 'a'][target[i] - 'a'] == -1) return -1;
                ans += shortestPath[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};