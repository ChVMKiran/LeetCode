class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        bitset<201> bs;
        bool flag = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > n - 1) return false;
            if(bs.test(nums[i])) {
                if(nums[i] < n - 1 || flag) return false;
                flag = 1;
                continue;
            }
            bs.set(nums[i]);
        }
        return flag;
    }
};