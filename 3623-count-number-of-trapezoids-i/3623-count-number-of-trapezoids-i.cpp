class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long comb = 0, ans = 0;
        int mod = 1e9 + 7;
        unordered_map<int, int> mpp;
        for(auto &point :points) {
            mpp[point[1]]++;
        }
        for(auto &[_, freq] : mpp) {
            long long val = (1LL * freq * (freq - 1)) / 2;
            ans += val * comb;
            comb += val;
        }
        return ans % mod;
    }
};