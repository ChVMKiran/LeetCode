class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for(auto &q :queries) {
            preSum[q[0]]++;
            preSum[q[1] + 1]--;
        }
        for(int i = 0; i < n; i++) {
            if(i) preSum[i] += preSum[i - 1];
            nums[i] -= preSum[i];
            if(nums[i] > 0) return false;
        }
        return true;
    }
};