class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        queue<tuple<int, int, int>> qu;
        qu.push({0, 0, 0});
        while(!qu.empty()) {
            auto [node, price, stops] = qu.front();
            qu.pop();
            if(stops > k) continue;
            for(auto& [nn, c] :adj[node]) {
                if(cost[nn] > price + c) {
                    qu.push({nn, price + c, stops + 1});
                    cost[nn] = price + c;
                }
            }
        }
        if(cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};