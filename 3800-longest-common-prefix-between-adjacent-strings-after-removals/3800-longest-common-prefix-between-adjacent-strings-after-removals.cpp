class Solution {
    int fun(string &s, string &t) {
        int cnt = 0;
        for(int i = 0; i < min(s.size(), t.size()); i++) {
            if(s[i] != t[i]) return cnt;
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> vec(n - 1), pre(n - 1), suf(n - 1);
        vector<int> ans(n);
        if(n < 3) return ans;
        for(int i = 0; i < n - 1; i++) {
            vec[i] = fun(words[i], words[i + 1]);
            pre[i] = vec[i];
            if(i) pre[i] = max(pre[i], pre[i - 1]);
        }
        suf[n - 2] = vec[n - 2];
        for(int i = n - 3; i >= 0; i--) {
            suf[i] = max(suf[i + 1], vec[i]);
        }
        for(int i = 0; i < n; i++) {
            if(i > 1) ans[i] = max(ans[i], pre[i - 2]);
            if(i < n - 2) ans[i] = max(ans[i], suf[i + 1]);
            if(i && i < n - 1) ans[i] = max(ans[i], fun(words[i - 1], words[i + 1]));
        }
        return ans;
    }
};
// 0 3 0 0
// 0 3 3 3
// 3 3 0 0