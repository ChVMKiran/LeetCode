class Solution {
public:
    using pi = pair<int, int>;
    using ll = long long;
    vector<ll> dijkstra(int src, vector<vector<tuple<int, int, int>>>& adj, bool isTaxed) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<ll> cost(adj.size(), INT_MAX);
        cost[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if(cost[node] != dist) continue;
            for(auto& [nn, c, t]: adj[node]) {
                ll price = dist + (ll)c * (isTaxed ? t: 1);
                if(cost[nn] > price) {
                    cost[nn] = price;
                    pq.push({price, nn});
                }
            }
        }
        return cost;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<tuple<int, int, int>>> adj(n);
        for(auto& r: roads) {
            adj[r[0]].push_back({r[1], r[2], r[3]});
            adj[r[1]].push_back({r[0], r[2], r[3]});
        }
        vector<int> ans(n, INT_MAX);
        for(int i = 0; i < n; i++) {
            vector<ll> travelCosts = dijkstra(i, adj, false);
            vector<ll> returnCosts = dijkstra(i, adj, true);
            ll mini = INT_MAX;
            for(int j = 0; j < n; j++) {
                ll cost = travelCosts[j] + returnCosts[j] + prices[j];
                mini = min(mini, cost);
                // cout<<j<<' '<<travelCosts[j]<<' '<<returnCosts[j]<<' '<<cost<<'\n';
            }
            // cout<<"------------------------------------\n";
            ans[i] = (int)mini;
        }
        return ans;
    }
};