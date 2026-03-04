class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> rows(m), cols(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!mat[i][j]) continue;
                rows[i]++;
                cols[j]++;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rows[i] == 1 && cols[j] == 1 && mat[i][j]) ans++;
            }
        }
        return ans;
    }
};