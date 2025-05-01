class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++) {
            int m = res.size(), j = 0;
            string curr;
            while(j < m) {
                int cnt = 1;
                while(j < m - 1 && res[j] == res[j + 1]) {
                    cnt++;
                    j++;
                }
                curr += to_string(cnt) + res[j];
                j++;
            }
            res = curr;
        }
        return res;
    }
};