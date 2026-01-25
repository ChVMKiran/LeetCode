class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size(), val = 0;
        for(int i = 0; i < n; i++) {
            val ^= nums[i];
        }
        int lastSetBit = val & (-(long)val);
        for(int i = 0; i < n; i++) {
            if((lastSetBit & nums[i])) ans[0] ^= nums[i];
            else ans[1] ^= nums[i];
        }
        return ans;
    }
};