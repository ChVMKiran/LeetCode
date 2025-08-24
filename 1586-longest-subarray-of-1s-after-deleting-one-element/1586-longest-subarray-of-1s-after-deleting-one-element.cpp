class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool flag = false;
        int n = nums.size(), ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(!nums[i]) {
                if(flag) {
                    while(nums[j]) j++;
                    j++;
                }
                else flag = true;
            }
            ans = max(ans, i - j + 1 - flag);
        }
        return min(ans, n - 1);
    }
};