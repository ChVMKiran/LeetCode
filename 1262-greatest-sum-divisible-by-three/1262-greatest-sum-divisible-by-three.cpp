class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0, one1 = INT_MAX, one2 = INT_MAX, two1 = INT_MAX, two2 = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            ans += nums[i];
            if(nums[i] % 3 == 1) {
                if(one1 > nums[i]) {
                    one2 = one1;
                    one1 = nums[i];
                }
                else if(one2 > nums[i]) {
                    one2 = nums[i];
                }
            }
            else if(nums[i] % 3 == 2) {
                if(two1 > nums[i]) {
                    two2 = two1;
                    two1 = nums[i];
                }
                else if(two2 > nums[i]) {
                    two2 = nums[i];
                }
            }
        }
        if(ans % 3 == 1) {
            if(one1 != INT_MAX && two2 != INT_MAX) ans -= min(one1, two1 + two2);
            else if(one1 != INT_MAX) ans -= one1;
            else if(two2 != INT_MAX) ans -= (two1 + two2);
            else return 0;
        }
        else if(ans % 3 == 2) {
            if(two1 != INT_MAX && one2 != INT_MAX) ans -= min(two1, one1 + one2);
            else if(two1 != INT_MAX) ans -= two1;
            else if(one2 != INT_MAX) ans -= (one1 + one2);
            else return 0;
        }
        return ans;
    }
};