class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size(), offset = 1 << 7, mask = (1 << 8) - 1;
        for(int i = 0; i < n; i++) {
            nums[i] += offset;
        }
        for(int i = 0; i < n; i++) {
            int curr = nums[i] - offset;
            int val = nums[((curr + i) % n + n) % n] & mask;
            nums[i] |= val << 8;
        }
        for(int i = 0; i < n; i++) {
            nums[i] = (nums[i] >> 8) - offset;
        }
        return nums;
    }
};