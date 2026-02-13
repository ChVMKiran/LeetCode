class Solution {
public:
    struct Hash {
        long long operator()(const pair<int, int>& p) const {
            auto &[d1, d2] = p;
            return ((long long)(d1 + 100000) << 21) | (d2 + 100000);
        }
    };
    int twoEquals(string s, char x, char y, char z) {
        int res = 1, x_cnt = 0, y_cnt = 0, n = s.size();
        unordered_map<long long, int> ump;
        ump[0] = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == z) {
                ump.clear();
                ump[0] = i;
                x_cnt = 0;
                y_cnt = 0;
                continue;
            }
            else if(s[i] == x) x_cnt++;
            else y_cnt++;

            if(ump.count(x_cnt - y_cnt)) res = max(res, i - ump[x_cnt - y_cnt]);
            else ump[x_cnt - y_cnt] = i;
        }
        return res;
    }
    int longestBalanced(string s) {
        int n = s.size(), ans = 1, curr = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) curr++;
            else curr = 1;
            ans = max(ans, curr);
        }
        ans = max(ans, twoEquals(s, 'a', 'b', 'c'));
        ans = max(ans, twoEquals(s, 'b', 'c', 'a'));
        ans = max(ans, twoEquals(s, 'c', 'a', 'b'));
        unordered_map<pair<int, int>, int, Hash> ump;
        ump[{0, 0}] = -1;
        int a_cnt = 0, b_cnt = 0, c_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a_cnt++;
            else if(s[i] == 'b') b_cnt++;
            else c_cnt++;
            int d1 = a_cnt - b_cnt, d2 = a_cnt - c_cnt;
            if(ump.count({d1, d2})) 
                ans = max(ans, i - ump[{d1, d2}]);
            else ump[{d1, d2}] = i;
        }
        return ans;
    }
};