class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(mat[i][j] == 0) continue;
                int val = 10001;
                if(i > 0) val = min(val, 1 + mat[i - 1][j]);
                if(j > 0) val = min(val, 1 + mat[i][j - 1]);
                mat[i][j] = val;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(mat[i][j] == 0) continue;
                int val = mat[i][j];
                if(i < m - 1) val = min(val, 1 + mat[i + 1][j]);
                if(j < n - 1) val = min(val, 1 + mat[i][j + 1]);
                mat[i][j] = val;
            }
        }
        return mat;
    }
};