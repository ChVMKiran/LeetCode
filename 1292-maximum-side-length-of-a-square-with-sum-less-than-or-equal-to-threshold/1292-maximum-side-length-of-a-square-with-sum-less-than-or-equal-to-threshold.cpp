class Solution {
public:
    int getRect(vector<vector<int>>& pre, int x1, int y1, int x2, int y2) {
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), ans = 0, low = 1, high = min(m, n);
        vector<vector<int>> pre(m + 1, vector<int> (n + 1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pre[i + 1][j + 1] = mat[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
            }
        }
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool flag = false;
            for(int i = 1; i <= m - mid + 1; i++) {
                for(int j = 1; j <= n - mid + 1; j++) {
                    int curr = getRect(pre, i, j, i + mid - 1, j + mid - 1);
                    if(curr <= threshold) {
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};