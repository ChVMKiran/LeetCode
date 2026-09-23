class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = -1;
        long long total = accumulate(nums.begin(), nums.end(), 0), curr = 0;
        if(total < x) return -1;
        for(int i = 0, j = 0; i < n; i++) {
            curr += nums[i];
            while(curr > total - x) {
                curr -= nums[j++];
            }
            if(curr == total - x) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans == -1 ? ans : n - ans;
    }
};