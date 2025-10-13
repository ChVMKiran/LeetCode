class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            ump[nums[i]]++;
        }
        vector<int> unq;
        for(auto &[ele, _] : ump) {
            unq.push_back(ele);
        }
        int m = unq.size();
        sort(unq.begin(),unq.end());
        vector<int> dp(m);
        dp[0] = unq[0] * ump[unq[0]];
        for(int i = 1; i < m; i++) {
            if(unq[i] - unq[i - 1] == 1) {
                dp[i] = max(dp[i - 1], unq[i] * ump[unq[i]] + (i > 1 ? dp[i - 2] : 0));
            }
            else {
                dp[i] = dp[i - 1] + unq[i] * ump[unq[i]];
            }
        }
        return dp[m - 1];
    }
};