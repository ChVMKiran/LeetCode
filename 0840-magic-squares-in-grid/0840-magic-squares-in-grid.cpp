class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int &x, int &y) {
        int totalSum = 0, top = 0, bottom = 0, left = 0, right = 0, d1 = 0, d2 = 0;
        int freq[9] = {0};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int &val = grid[x + i][y + j];
                if(val == 0 || val > 9) return false;
                if(freq[val - 1] == 1) return false;
                freq[val - 1] = 1;
                totalSum += val;
                if(i == 0) top += val;
                if(j == 0) left += val;
                if(i == 2) bottom += val;
                if(j == 2) right += val;
                if(i == j) d1 += val;
                if(i + j == 2) d2 += val;
            }
        }
        return (totalSum == top * 3) && (top == bottom) && (bottom == left) && (left == right) && (right == d1) && (d1 == d2);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(isMagicSquare(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};