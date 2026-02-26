class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), c = 0, ans = 0;
        while(--n > 0) {
            int b = (s[n] - '0') + c;
            if(b == 1) {
                ans += 2;
                c = 1;
            }
            else {
                ans++;
            }
        }
        return ans + c;
    }
};