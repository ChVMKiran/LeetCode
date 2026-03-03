class Solution {
public:
    vector<int> helper(vector<int>& nums, int parity) {
        int n = nums.size(), cnt = 0, mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++, parity = !parity) {
            if((nums[i] & 1) != parity) {
                mini = min(mini, nums[i] + 1);
                maxi = max(maxi, nums[i] - 1);
                cnt++;
            }
            else {
                mini = min(mini, nums[i]);
                maxi = max(maxi, nums[i]);
            }
        }
        if(mini == maxi && cnt) return {cnt, 1};
        return {cnt, maxi - mini};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums, 1));
    }
};