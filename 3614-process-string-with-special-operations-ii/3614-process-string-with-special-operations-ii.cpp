class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                if(len) len--;
            }
            else if(s[i] == '#') len <<= 1;
            else if(s[i] == '%') continue;
            else len++;
        }
        if(len <= k) return '.';
        char last = '.', res = '.';
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '*') { 
                if(len) len++; 
            }
            else if(s[i] == '#') len >>= 1, k = k - len < 0 ? k : k - len;
            else if(s[i] == '%') k = len - k - 1;
            else {
                last = s[i], len--;
            }
            if(len < k) break;
            if(len == k) {
                res = last; 
                break;
            }
        }
        return res;
    }
};