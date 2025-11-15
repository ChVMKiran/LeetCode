class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(), zeroes = 0, ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') ans += zeroes;
            else {
                while(i >= 0 && s[i] == '0') i--;
                i++;
                zeroes++;
            }
        }
        return ans;
    }
};