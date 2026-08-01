class Solution {
public:
    long long dp[20][20];
    int n;
    long long helper(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return dp[i][j] = nums[i];
        long long res1 = nums[i] + min(helper(i + 1, j - 1, nums), helper(i + 2, j, nums));
        long long res2 = nums[j] + min(helper(i, j - 2, nums), helper(i + 1, j - 1, nums));
        return dp[i][j] = max(res1, res2);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        long long maxSum = helper(0, n - 1, nums);
        long long totalSum = accumulate(nums.begin(), nums.end(), 0);
        return 2 * maxSum >= totalSum;
    }
};