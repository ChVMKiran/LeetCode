class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size(), cnt1 = 0, cnt2 = 0, prev1 = 1, prev2 = 1;
        bool flag1 = true, flag2 = true;
        for(int i = 0; i < n - 1; i++) {
            int val = nums[i];
            if(flag1) {
                if(val * prev1 == -1) {
                    // nums[i] = 1;
                    prev1 = -1;
                    cnt1++;
                    if(cnt1 > k) {
                        flag1 = false;
                    }
                }
                else if(val == -1) prev1 = 1;
            }
            if(flag2) {
                if(val * prev2 == 1){
                    // nums[i] = -1;
                    prev2 = -1;
                    cnt2++;
                    if(cnt2 > k) {
                        flag2 = false;
                    }
                }
                else if(val == 1) prev2 = 1;
            }
        }
        if(nums[n - 1] * prev1 != 1) flag1 = false;
        if(nums[n - 1] * prev2 != -1) flag2 = false;
        return flag1 || flag2;
    }
};