class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int> (n + 1));
        for(auto &query: queries) {
            int row1 = query[0], col1 = query[1], row2 = query[2], col2 = query[3];
            diff[row1][col1] += 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }
        vector<vector<int>> mat(n, vector<int> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int up = i ? mat[i - 1][j] : 0;
                int left = j ? mat[i][j - 1] : 0;
                int upleft = (i && j) ? mat[i - 1][j - 1] : 0;
                mat[i][j] = diff[i][j] + up + left - upleft;
            }
        }
        return mat;
    }
};