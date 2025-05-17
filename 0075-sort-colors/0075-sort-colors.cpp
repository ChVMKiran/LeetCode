class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ind = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(!nums[i]) swap(nums[ind++], nums[i]);
        }
        for(int i = ind; i < n; i++) {
            if(nums[i] == 1) swap(nums[ind++], nums[i]);
        }
    }
};