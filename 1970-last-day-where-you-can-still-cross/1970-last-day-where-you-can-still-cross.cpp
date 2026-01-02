class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        vector<vector<bool>> canReachTop(row, vector<bool> (col, false)), 
        canReachBottom(row, vector<bool> (col, false)), 
        isLand(row, vector<bool> (col, false));

        for(int i = row * col - 1; i >= 0; i--) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            isLand[x][y] = true;
            if(x == 0 || x && canReachTop[x - 1][y] || y && canReachTop[x][y - 1] || x < row - 1 && canReachTop[x + 1][y] || y < col - 1 && canReachTop[x][y + 1]) {
                if(!canReachTop[x][y]) {
                    canReachTop[x][y] = true;
                    queue<pair<int, int>> qu;
                    qu.emplace(x, y);
                    while(!qu.empty()) {
                        auto [x1, y1] = qu.front();
                        qu.pop();
                        if(canReachBottom[x1][y1]) return i;
                        for(int j = 0; j < 4; j++) {
                            int nx = x1 + dx[j], ny = y1 + dy[j];
                            if(nx < 0 || ny < 0 || nx == row || ny == col || !isLand[nx][ny] || canReachTop[nx][ny]) continue;

                            canReachTop[nx][ny] = true;
                            qu.emplace(nx, ny);
                        }
                    }
                }
            }
            if(x == row - 1 || x && canReachBottom[x - 1][y] || y && canReachBottom[x][y - 1] || x < row - 1 && canReachBottom[x + 1][y] || y < col - 1 && canReachBottom[x][y + 1]) {
                if(!canReachBottom[x][y]) {
                    canReachBottom[x][y] = true;
                    queue<pair<int, int>> qu;
                    qu.emplace(x, y);
                    while(!qu.empty()) {
                        auto [x1, y1] = qu.front();
                        qu.pop();
                        if(canReachTop[x1][y1]) return i;
                        for(int j = 0; j < 4; j++) {
                            int nx = x1 + dx[j], ny = y1 + dy[j];
                            if(nx < 0 || ny < 0 || nx == row || ny == col || !isLand[nx][ny] || canReachBottom[nx][ny]) continue;

                            canReachBottom[nx][ny] = true;
                            qu.emplace(nx, ny);
                        }
                    }
                }
            }

            if(canReachTop[x][y] && canReachBottom[x][y]) return i;
        }
        return 0;
    }
};