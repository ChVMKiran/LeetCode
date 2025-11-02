class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> isGuarded(m, vector<int>(n, 0));
        for (const auto& guard : guards) {
            isGuarded[guard[0]][guard[1]] = 1;
        }
        for (auto& wall : walls) {
            isGuarded[wall[0]][wall[1]] = -1;
        }
        for (auto& guard : guards) {
            int row = guard[0], col = guard[1];
            for (int r = row - 1; r >= 0; r--) {
                if (isGuarded[r][col] == -1 || isGuarded[r][col] == 1)
                    break;
                isGuarded[r][col] = 2;
            }
            for (int r = row + 1; r < m; r++) {
                if (isGuarded[r][col] == -1 || isGuarded[r][col] == 1)
                    break;
                isGuarded[r][col] = 2;
            }
            for (int c = col - 1; c >= 0; c--) {
                if (isGuarded[row][c] == -1 || isGuarded[row][c] == 1)
                    break;
                isGuarded[row][c] = 2;
            }
            for (int c = col + 1; c < n; c++) {
                if (isGuarded[row][c] == -1 || isGuarded[row][c] == 1)
                    break;
                isGuarded[row][c] = 2;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += (isGuarded[i][j] == 0);
            }
        }
        return ans;
    }
};