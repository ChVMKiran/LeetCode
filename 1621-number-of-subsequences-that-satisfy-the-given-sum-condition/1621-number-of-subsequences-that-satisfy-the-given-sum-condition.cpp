class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1, mod = 1e9 + 7, ans = 0;
        vector<int> twos(high + 1);
        twos[0] = 1;
        for(int i = 1; i <= high; i++) {
            twos[i] = (twos[i - 1] * 2) % mod;
        }
        while(low <= high) {
            if(nums[low] + nums[high] <= target) {
                ans = (ans + twos[high - low]) % mod;
                low++;
            }
            else high--;
        }
        return ans;
    }
};