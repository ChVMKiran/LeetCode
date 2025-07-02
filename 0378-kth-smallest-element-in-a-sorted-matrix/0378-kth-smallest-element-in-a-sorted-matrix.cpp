class Solution {
public:
    int helper(vector<vector<int>>& matrix, int val) {
        int n = matrix.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(matrix[i][n - 1] <= val) cnt += n;
            else if(matrix[i][0] <= val) cnt += upper_bound(matrix[i].begin(), matrix[i].end(), val) - matrix[i].begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int mini = matrix[0][0], maxi = matrix[n - 1][n - 1];
        if(k == 1) return mini;
        if(k == n * n) return maxi;
        while(mini < maxi) {
            int mid = mini + (maxi - mini) / 2;
            if(helper(matrix, mid) >= k) maxi = mid;
            else mini = mid + 1;
        }
        return maxi;
    }
};