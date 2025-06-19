class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, prev = nums[0], n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] - prev > k) {
                prev = nums[i];
                ans++;
            }
        }
        return ans;
    }
};