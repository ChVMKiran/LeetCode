class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), lastInd = 0, ans = triangle[0][0];
        vector<int> prev = triangle[0];
        for(int i = 1; i < n; i++) {
            vector<int> curr = triangle[i];
            curr[0] += prev[0];
            curr[i] += prev[i - 1];
            if(i == n - 1) ans = min(curr[0], curr[i]);
            for(int j = 1; j < i; j++) {
                curr[j] += min(prev[j - 1], prev[j]);
                if(i == n - 1) ans = min(ans, curr[j]);
            }
            prev = curr;
        }
        return ans;
    }
};