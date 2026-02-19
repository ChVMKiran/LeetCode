class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, n = s.size(), prev = 0, curr = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                curr++;
            }
            else {
                prev = curr;
                curr = 1;
            }
            if(prev >= curr) ans++;
        }
        return ans;
    }
};