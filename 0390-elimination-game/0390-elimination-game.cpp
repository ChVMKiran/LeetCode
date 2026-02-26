class Solution {
public:
    int lastRemaining(int n) {
        bool ltor = true;
        int ans = 1;
        int diff = 1; // diff b/w adj elements at each step
        while(n > 1) {
            if(ltor || n % 2) ans += diff;
            n >>= 1;
            diff <<= 1;
            ltor = !ltor;
        }
        return ans;
    }
};