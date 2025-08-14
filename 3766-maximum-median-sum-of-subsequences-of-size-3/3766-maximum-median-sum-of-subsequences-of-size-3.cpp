class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        if(n <= 2) return 0ll;
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i = n - 2; i >= l; i -= 2) {
            ans += static_cast<long long>(nums[i]);
            l++;
        }
        return ans;
    }
};