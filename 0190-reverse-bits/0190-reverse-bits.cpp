class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            ans *= 2;
            if(n & 1) ans += 1;
            n >>= 1;
        }
        return ans;
    }
};