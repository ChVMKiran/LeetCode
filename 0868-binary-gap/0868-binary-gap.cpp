class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, curr = -1;
        while(n) {
            if(n & 1) {
                if(curr != -1) ans = max(ans, curr + 1);
                curr = 0;
            }
            else if(curr != -1) {
                curr++;
                ans = max(ans, curr + 1);
            }
            n >>= 1;
        }
        return ans;
    }
};