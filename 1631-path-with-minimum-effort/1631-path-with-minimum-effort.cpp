class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), ans = INT_MIN;
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> eff(m, vector<int> (n, INT_MAX));
        int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
        pq.push({0, {0, 0}});
        eff[0][0] = 0;
        while(!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(effort != eff[x][y]) continue;
            if(x == m - 1 && y == n - 1) break;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) { 
                    int newEff = max(eff[x][y], abs(heights[nx][ny] - heights[x][y]));
                    if(newEff < eff[nx][ny]) {
                        eff[nx][ny] = newEff;
                        pq.push({newEff, {nx, ny}});
                    }
                }
            }
        }
        return eff[m - 1][n - 1];
    }
};