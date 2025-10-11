class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<int, int> ump;
        vector<int> unqPowers;
        for(int i = 0; i < n; i++) {
            ump[power[i]]++;
            if(ump[power[i]] == 1) unqPowers.push_back(power[i]);
        }
        sort(unqPowers.begin(),unqPowers.end());
        long long ans = 0;
        int m = unqPowers.size();
        vector<long long> dp(m);
        dp[0] = (long long)unqPowers[0] * ump[unqPowers[0]];
        for(int i = 1; i < m; i++) {
            dp[i] = (long long)unqPowers[i] * ump[unqPowers[i]];
            int j = i - 1;
            while(j >= 0 && unqPowers[i] <= unqPowers[j] + 2) j--;
            if(j >= 0) dp[i] += dp[j];
            dp[i] = max(dp[i - 1], dp[i]);
        }
        return dp[m - 1];
    }
};