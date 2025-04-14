class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long bigDiff = 0, large = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, bigDiff * nums[i]);
            bigDiff = max(bigDiff, large - nums[i]);
            large = max(large, static_cast<long long>(nums[i]));
        }
        return ans;
    }
};