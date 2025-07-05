class Solution {
public:
    int helper(vector<int>& nums, int val) {
        int cnt = 1, n = nums.size(), curr = 0;
        for(int i = 0; i < n; i++) {
            curr += nums[i];
            if(curr > val) {
                curr = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int high = 0, low = nums[0], n = nums.size();
        for(int i = 0; i < n; i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(helper(nums, mid) <= k) high = mid;
            else low = mid + 1;
        }
        return high;
    }
};