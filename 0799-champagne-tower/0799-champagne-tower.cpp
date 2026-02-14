class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double wine[100][100] = {0};
        wine[0][0] = poured;
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= i; j++) {
                wine[i + 1][j] += max(0.0, wine[i][j] - 1) / 2.0;
                wine[i + 1][j + 1] += max(0.0, wine[i][j] - 1) / 2.0;
            }
        }
        return min(1.0, wine[query_row][query_glass]);
    }
};