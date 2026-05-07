class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m), closest(n), left(n), right(n);
        for(int i = 0; i < n; i++) {
            int ind = i, diff = INT_MAX;
            if(i > 0) {
                diff = nums[i] - nums[i - 1];
                ind = i - 1;
            }
            if(i < n - 1 && diff > nums[i + 1] - nums[i]) {
                ind = i + 1;
            }
            closest[i] = ind;
        }
        for(int i = 1; i < n; i++) {
            if(closest[i - 1] == i) {
                left[i] = left[i - 1] + 1;
            }
            else {
                left[i] = left[i - 1] + (nums[i] - nums[i - 1]);
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(closest[i + 1] == i) {
                right[i] = right[i + 1] + 1;
            }
            else {
                right[i] = right[i + 1] + (nums[i + 1] - nums[i]);
            }
        }
        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if(l <= r) ans[i] = left[r] - left[l];
            else ans[i] = right[r] - right[l];
        }
        return ans;
    }
};