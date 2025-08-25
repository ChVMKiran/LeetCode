class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ind = 0;
        vector<int> vec(m * n);
        for(int i = 0; i < m + n - 1; i++) {
            if(i % 2) {
                int j = 0, k = i;
                if(i > n - 1) {
                    j = i - n + 1;
                    k = i - j;
                }
                while(j < m && k >= 0) {
                    vec[ind++] = mat[j][k];
                    j++, k--;
                }
            }
            else {
                int j = i, k = 0;
                if(i > m - 1) {
                    k = i - m + 1;
                    j = i - k;
                }
                // if(i == 2) cout<<j<<k;
                while(j >= 0 && k < n) {
                    vec[ind++] = mat[j][k];
                    j--, k++;
                }
            }
        }
        return vec;
    }
};