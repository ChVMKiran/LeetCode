class Solution {
public:
    struct Hash {
        size_t operator()(tuple<int,long long,long long> const& t) const {
            auto [a,b,c] = t;
            size_t h = a;
            h ^= b + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
            h ^= c + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
            return h;
        }
    };

    int countSequences(vector<int>& nums, long long k) {
        unordered_map<tuple<int,long long,long long>, long long, Hash> dp;
        int n = nums.size();

        auto dfs = [&](auto&& self, int i, long long num, long long den) -> long long {

            long long g = gcd(num, den);
            num /= g;
            den /= g;

            if (i == n)
                return (double)num / den == k;

            auto key = make_tuple(i, num, den);
            if (dp.count(key)) return dp[key];

            long long res = 0;

            // leave
            res += self(self, i+1, num, den);

            // multiply
            res += self(self, i+1, num * nums[i], den);

            // divide
            res += self(self, i+1, num, den * nums[i]);

            return dp[key] = res;
        };

        return dfs(dfs, 0, 1, 1);
    }
};