class Solution {
public:
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> upDp(m, 1), downDp(m, 1), upPre(m + 1), downPre(m + 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                upPre[j + 1] = (upPre[j] + upDp[j]) % mod;
                downPre[j + 1] = (downPre[j] + downDp[j]) % mod;
            }
            for(int j = 0; j < m; j++) {
                upDp[j] = downPre[j];
                downDp[j] = (upPre[m] - upPre[j + 1] + mod) % mod; // sum(upPre[x]) where x is in j+1...m range
            }
        }
        long ans = 0;
        for(int i = 0; i < m; i++) {
            ans = (ans + upDp[i] + downDp[i]) % mod;
        }
        return (int)ans;
    }
};