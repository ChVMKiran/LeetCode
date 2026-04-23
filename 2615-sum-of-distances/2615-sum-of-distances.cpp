class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<long long>> inds;

        for(int i = 0; i < n; i++) {
            inds[nums[i]].push_back(i);
        }

        for(auto &[_, vec]: inds) {
            long long pre = 0, total = accumulate(vec.begin(), vec.end(), 0LL);
            for(int i = 0; i < vec.size(); i++) {
                ans[vec[i]] = total - 2 * pre + vec[i] * (2 * i - vec.size());
                pre += vec[i];
            }
        }

        return ans;
    }
};