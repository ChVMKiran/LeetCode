class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), mini = INT_MAX, k = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
                if(matrix[i][j] < 0) k++;
            }
        }
        if(k % 2) ans -= mini * 2;
        return ans;
    }
};