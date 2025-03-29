class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += abs(nums[i] - nums[n/2]);
        }
        return total;
    }
};