class Solution {
  public:
    vector<string> ans;
    void solve(string &s, int ind, int val, string curr) {
        int cnt = count(curr.begin(), curr.end(), '.');
        if(cnt > 3) return;
        if(ind == s.size()) {
            if(cnt != 3 || val > 255) return;
            ans.push_back(curr);
            return;
        }
        if(val > 255) return;
        if(val || curr.empty()) solve(s, ind + 1, val * 10 + s[ind] - '0', curr + s[ind]);
        if(!curr.empty()) solve(s, ind + 1, s[ind] - '0', curr + '.' + s[ind]);
    }
    vector<string> restoreIpAddresses(string &s) {
        solve(s, 0, 0, "");
        return ans;
    }
};