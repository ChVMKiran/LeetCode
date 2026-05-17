class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int cnt = 0, m = matrix.size(), n = matrix[0].size(), maxi = 0;
        vector<vector<pair<int, int>>> ump(201);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ump[matrix[i][j]].push_back({i, j});
                maxi = max(maxi, matrix[i][j]);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int e = matrix[i][j];
                if(!e) continue;
                bool flag = true;
                for(int k = e + 1; k <= maxi && flag; k++) {
                    for(auto &[x, y]: ump[k]) {
                        if(abs(x - i) > e || abs(y - j) > e) continue;
                        if(abs(x - i) == e && abs(y - j) == e) continue;
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};
