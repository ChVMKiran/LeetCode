class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int last0 = 0, last1 = 0, curr = 0, val = -1, ones = ranges::count(s, '1'), ans = ones;
        for(auto&c : s) {
            if(c - '0' == val) curr++;
            else {
                if(c == '0') last1 = curr;
                else last0 = curr;
                val = c - '0';
                curr = 1;
            }
            if(val == 1) ans = max(ans, curr);
            else {
                if(last0 && last1) ans = max(ans, curr + ones + last0);
            }
        }
        return ans;
    }
};