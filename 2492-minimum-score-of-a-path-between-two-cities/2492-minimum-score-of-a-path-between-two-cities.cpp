class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0] - 1].push_back(i);
            adj[roads[i][1] - 1].push_back(i);
        }
        int ans = INT_MAX;
        queue<int> qu;
        vector<int> vis(roads.size());
        qu.push(0);
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for(auto& ind: adj[node]) {
                int a = roads[ind][0] - 1, b = roads[ind][1] - 1, d = roads[ind][2];
                if(b == node) swap(a, b);
                if(!vis[ind]) {
                    vis[ind] = 1;
                    qu.push(b);
                    ans = min(ans, d);
                }
            }
        }
        return ans;
    }
};