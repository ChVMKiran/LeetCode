class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes = 0, n = nums.size(), ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            if(nums[r] == 0) {
                zeroes++;
                while(zeroes > k) {
                    if(nums[l] == 0) zeroes--;
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};