class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), curr_a = 0, curr_b = 0, ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') curr_a++;
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') {
                ans = min(ans, curr_b + curr_a);
                curr_b++;
            }
            else curr_a--;
        }
        ans = min(ans, curr_b + curr_a);
        return ans;
    }
};