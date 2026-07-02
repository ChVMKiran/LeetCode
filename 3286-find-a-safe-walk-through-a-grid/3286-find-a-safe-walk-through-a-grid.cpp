class Solution {
public:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        dist[0][0] = grid[0][0];
        while(!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0], nc = c + dirs[i][1];
                if(nr < 0 || nr == m || nc < 0 || nc == n) continue;
                int w = grid[nr][nc];
                if(dist[nr][nc] <= w + dist[r][c]) continue;
                dist[nr][nc] = w + dist[r][c];
                if(w == 0) dq.push_front({nr, nc}); // same cost, can be processed immediately
                else dq.push_back({nr, nc}); // its guarenteed that no cost > dist[r][c] + 1 
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};