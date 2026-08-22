class Solution {
private:
    long long limit;
    void getCombinations(const vector<int>& arr, int ind, int k, 
                        long long current, vector<long long>& result, int len) {
        if(current > limit) return;
        if (len == k) {
            result.push_back(current);
            return;
        }
        for (int i = ind; i < arr.size(); ++i) {
            getCombinations(arr, i + 1, k, lcm(current, arr[i]), result, len + 1);
        }
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> filtered;
        for (int c : coins) {
            bool divisible = false;
            for (int x : filtered) {
                if (c % x == 0) {
                    divisible = true;
                    break;
                }
            }
            if (!divisible) {
                filtered.push_back(c);
            }
        }

        limit = 1LL * k * filtered[0];

        int n = filtered.size();
        vector<vector<long long>> dic(n);
        
        for (int i = 0; i < n; ++i) {
            getCombinations(filtered, 0, i + 1, 1, dic[i], 0);
        }

        auto count = [&](long long target) {
            long long ans = 0;
            for (int i = 0; i < n; ++i) {
                long long sub_ans = 0;
                for (long long val : dic[i]) {
                    sub_ans += target / val;
                }
                if (i % 2 == 0) {
                    ans += sub_ans;
                } else {
                    ans -= sub_ans;
                }
            }
            return ans;
        };

        long long left = filtered[0];
        long long right = (long long)filtered[0] * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};