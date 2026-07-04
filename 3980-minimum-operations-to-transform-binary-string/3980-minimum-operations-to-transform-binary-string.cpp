class Solution {
public:
    int minOperations(string s1, string s2) {
        if(s1 == "1" && s2 == "0") return -1;
        int n = s1.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            char a = s1[i], b = s2[i];
            if(a == b) continue;
            if(a == '0') {
                s1[i] = '1';
                ans++;
            }
            else {
                if(i < n - 1 && s1[i + 1] == '1') {
                    ans++;
                    s1[i] = '0';
                    s1[i + 1] = '0';
                }
                else if(i && s1[i - 1] == '1') {
                    if(s2[i - 1] == '1') ans += 2;
                    else ans++;
                }
                else if(i < n - 1) {
                    ans += 2;
                    s1[i] = '0';
                }
                else {
                    ans += 2;
                    s1[i] = '0';
                }
            }
        }
        return ans;
    }
};