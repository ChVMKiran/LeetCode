class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, last = nums[0], n = nums.size();
        for(int i = 1; i < n; i++) {
            if(last < nums[i]) {
                ans = max(ans, nums[i] - last);
            }
            last = min(last, nums[i]);
        }
        return ans;
    }
};