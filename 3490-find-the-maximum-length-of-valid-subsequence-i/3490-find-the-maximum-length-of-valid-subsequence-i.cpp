class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int zero = 0, one = 0, zeroOne = 0, oneZero = 0;
        int flag1 = 0, flag2 = 1;
        for(int &num : nums) {
            if(num % 2 == 0) {
                zero++;
                if(flag1 == 0) {
                    zeroOne++;
                    flag1 = 1;
                }
                if(flag2 == 0) {
                    oneZero++;
                    flag2 = 1;
                }
            }
            else {
                one++;
                if(flag1 == 1) {
                    zeroOne++;
                    flag1 = 0;
                }
                if(flag2 == 1) {
                    oneZero++;
                    flag2 = 0;
                }
            }
        }
        return max({one, zero, zeroOne, oneZero});
    }
};