class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size(), mx = 0;
        long long gcds[5 * 10000 + 1] = {0}, freq[5 * 10000 + 1] = {0};
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            mx = max(mx, nums[i]);
        }
        for(int i = 1; i <= mx; i++) {
            for(int j = i * 2; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }
        for(int i = mx; i; i--) {
            gcds[i] += (freq[i] * (freq[i] - 1)) / 2;
            for(int j = i * 2; j <= mx; j += i) {
                gcds[i] -= gcds[j];
            }
        }
        for(int i = 1; i <= mx; i++) gcds[i] += gcds[i - 1];
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            auto& q = queries[i];
            ans[i] = lower_bound(gcds, gcds + mx, q + 1) - gcds;
        }
        return ans;
    }
};