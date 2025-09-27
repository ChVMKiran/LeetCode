class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int n = nums.size(), ind = n / 2;
        if(nums[ind] == k) return 0;
        else if(nums[ind] < k) {
            while(ind < n && nums[ind] < k) ans = ans + (long long)abs(nums[ind++] - k);
        }
        else {
            while(ind >= 0 && nums[ind] > k) ans = ans + (long long)abs(nums[ind--] - k);
        }
        return ans;
    }
};