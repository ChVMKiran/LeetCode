class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n), sufMin(n), ans(n);
        preMax[0] = nums[0];
        sufMin[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            preMax[i] = max(nums[i], preMax[i - 1]);
            sufMin[n - i - 1] = min(nums[n - i - 1], sufMin[n - i]);
        }

        ans[n - 1] = preMax[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            ans[i] = preMax[i];
            if(preMax[i] > sufMin[i + 1]) ans[i] = ans[i + 1];
        }
        return ans;
    }
};