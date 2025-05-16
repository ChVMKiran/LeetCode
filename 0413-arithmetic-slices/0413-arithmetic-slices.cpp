class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            if(nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) {
                i += 2;
                int cnt = 1;
                while(i < n - 1 && nums[i + 1] - nums[i] == nums[i] - nums[i - 1]) {
                    i++;
                    cnt++;
                }
                i--;
                ans += (cnt) * (cnt + 1) / 2;
            }
        }
        return ans;
    }
};