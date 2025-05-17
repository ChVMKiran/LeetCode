class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size() - 1;
        while(m <= r) {
            if(nums[m] == 1) m++;
            else if(nums[m]) swap(nums[m], nums[r--]);
            else swap(nums[l++], nums[m++]);
        }
    }
};