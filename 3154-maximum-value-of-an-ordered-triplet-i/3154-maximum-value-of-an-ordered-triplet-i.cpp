class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long bigDiff = 0, large = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            ans = max(ans, bigDiff * nums[i]);
            bigDiff = max(bigDiff, large - nums[i]);
            large = max(large, static_cast<long long>(nums[i]));
        }
        return ans;
    }
};