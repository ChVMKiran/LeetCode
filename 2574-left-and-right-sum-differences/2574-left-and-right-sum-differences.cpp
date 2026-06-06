class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            rightSum -= nums[i];
            ans[i] = abs(rightSum - leftSum);
            leftSum += nums[i];
        }
        return ans;
    }
};