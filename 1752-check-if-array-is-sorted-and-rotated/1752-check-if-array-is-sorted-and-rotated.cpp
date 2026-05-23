class Solution {
public:
    bool check(vector<int>& nums) {
        bool invert = false;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                if(invert) return false;
                invert = true;
            }
        }
        return true;
    }
};