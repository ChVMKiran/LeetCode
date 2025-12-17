class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == (cnt & 1)) cnt++;
        }
        return cnt;
    }
};