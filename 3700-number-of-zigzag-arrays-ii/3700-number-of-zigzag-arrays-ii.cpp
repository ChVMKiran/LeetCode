class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;
    using ll = long long;
    vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int n = a.size();
        vector<vector<ll>> c(n, vector<ll> (n));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if(b[k][j] == 0) continue;
                    c[i][j] =(c[i][j] % MOD + (a[i][k] % MOD * b[k][j] % MOD) % MOD) % MOD;
                }
            }
        }
        return c;
    }

    vector<vector<ll>> power(vector<vector<ll>>& base, int exp) {
        int n = base.size();
        vector<vector<ll>> res(n, vector<ll> (n));
        for(int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        while(exp) {
            if(exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int len = (m << 1);
        vector<vector<ll>> transMat(len, vector<ll> (len));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(j < i) transMat[i][j + m] = 1;
                else if(j > i) transMat[i + m][j] = 1;
            }
        }
        vector<ll> dp2(len);
        for(int i = 0; i < m; i++) {
            dp2[i] = i;
            dp2[i + m] = m - i - 1;
        }
        vector<ll> dpn(len);
        vector<vector<ll>> powerMat = power(transMat, n - 2);
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                dpn[i] = (dpn[i] + dp2[j] * powerMat[i][j]) % MOD;
            }
        }
        ll ans = 0;
        for(auto& e: dpn) {
            ans = (ans + e) % MOD;
        }
        return ans;
    }
};