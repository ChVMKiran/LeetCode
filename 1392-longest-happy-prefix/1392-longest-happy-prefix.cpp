class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        for(int i = 1, len = 0; i < n; i++) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
            else if(len > 0) {
                len = lps[len - 1];
                i--;
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};