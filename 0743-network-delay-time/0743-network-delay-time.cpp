class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int unvisited = n - 1;
        vector<vector<pair<int, int>>> adj(n);
        for(auto& time: times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k - 1] = 0;
        pq.push({0, k - 1});
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if(dist[node] != cost) continue;
            for(auto& [nn, w]: adj[node]) {
                if(dist[nn] > cost + w) {
                    if(dist[nn] == INT_MAX) unvisited--;
                    dist[nn] = cost + w;
                    pq.push({cost + w, nn});
                }
            }
        }
        if(unvisited) return -1;
        return *max_element(dist.begin(), dist.end());
    }
};