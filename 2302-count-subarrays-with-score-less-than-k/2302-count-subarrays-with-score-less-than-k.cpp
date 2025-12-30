class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long curr = 0, ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            curr += nums[i];
            while(curr * (i - j + 1) >= k) {
                curr -= nums[j];
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};