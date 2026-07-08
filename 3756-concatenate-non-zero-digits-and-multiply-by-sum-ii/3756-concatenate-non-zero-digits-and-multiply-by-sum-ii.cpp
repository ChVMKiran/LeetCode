class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), curr = 0, mod = 1e9 + 7;
        vector<int> sums(n + 1), tens(n + 1), cnts(n + 1), pre(n + 1);
        tens[0] = 1;
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            cnts[i + 1] = cnts[i] + (d > 0);
            sums[i + 1] = sums[i] + d;
            tens[i + 1] = (1LL * tens[i] * 10) % mod;
            pre[i + 1] = (d > 0) ? (1LL * pre[i] * 10 + d) % mod : pre[i];
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1] + 1;
            int len = cnts[r] - cnts[l];
            int sum = sums[r] - sums[l];
            int num = ((pre[r] - 1LL * pre[l] * tens[len]) % mod + mod) % mod;
            ans[i] = (1LL * num * sum) % mod;
        }
        return ans;
    }
};