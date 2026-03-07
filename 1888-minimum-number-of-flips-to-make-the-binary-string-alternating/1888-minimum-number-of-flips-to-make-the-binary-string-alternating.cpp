class Solution {
public:
    int minFlips(string s) {
        int zo = 0, oz = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == i % 2) zo++;
            else oz++;
        }
        int ans = min(oz, zo);
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == i % 2) {
                zo--;
                if(s[i] - '0' == (n + i) % 2) zo++;
                else oz++;
            }
            else {
                oz--;
                if(s[i] - '0' == (n + i) % 2) zo++;
                else oz++;
            }
            ans = min({ans, oz, zo});
        }
        return ans;
    }
};
