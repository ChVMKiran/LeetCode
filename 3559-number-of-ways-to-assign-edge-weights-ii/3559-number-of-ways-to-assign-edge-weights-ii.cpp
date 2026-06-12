class Solution {
public:
    const int LOG = 17;
    int dist(int x, int y, vector<vector<int>>& up, vector<int>& level) {
        if(level[x] < level[y]) swap(x, y);
        int diff = level[x] - level[y], res = 0;
        for(int i = 0; i < LOG; i++) {
            if(diff & (1 << i)) res += (1 << i), x = up[x][i];
        }
        if(x == y) return res;
        for(int i = LOG - 1; i >= 0; i--) {
            if(up[x][i] != up[y][i]) {
                x = up[x][i];
                y = up[y][i];
                res += (2 << i);
            }
        }
        return res + 2;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1, mod = 1e9 + 7, maxi = 1;
        vector<vector<int>> adj(n + 1);
        for(auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> level(n + 1, 1);
        vector<vector<int>> up(n + 1, vector<int> (LOG));
        queue<int> qu;
        qu.push(1);
        while(!qu.empty()) {
            auto node = qu.front();
            qu.pop();
            for(int& nn: adj[node]) {
                if(up[node][0] == nn) continue;
                level[nn] = level[node] + 1;
                up[nn][0] = node;
                for(int i = 1; i < LOG; i++) up[nn][i] = up[ up[nn][i - 1] ][i - 1];
                qu.push(nn);
            }
        }
        int m = queries.size();
        vector<int> ans(m), pow2(n);
        pow2[0] = 1;
        for(int i = 1; i < n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % mod;
        }
        for(int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            // int ancestor = lca(x, y, up, level);
            // int len = level[x] + level[y] - 2 * level[ancestor];
            // ans[i] = len == 0 ? 0 : pow2[len - 1];
            int len = dist(x, y, up, level);
            ans[i] = len == 0 ? 0 : pow2[len - 1];
        }
        return ans;
    }
};