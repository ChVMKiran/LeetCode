class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int val = 1;
        vector<int> powers;
        vector<int> res(queries.size());
        while(n) {
            if(n & 1) powers.push_back(val);
            val *= 2;
            n /= 2;
        }
        vector<vector<int>> dp(powers.size(), vector<int> (powers.size()));
        for(int i = 0; i < powers.size(); i++) {
            val = 1;
            for(int j = i; j < powers.size(); j++) {
                val = (static_cast<long long> (val) * powers[j]) % int(1e9 + 7);
                dp[i][j] = val;
            }
        }
        for(int i = 0; i < queries.size(); i++) {
            res[i] = dp[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};