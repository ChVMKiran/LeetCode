class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> ump;
            for (int j = i; j < i + k; j++) {
                ump[nums[j]]++;
            }
            vector<pair<int, int>> vec;
            for (auto &[ele, frq] : ump) {
                vec.push_back({frq, ele});
            }
            sort(vec.begin(), vec.end(), greater<pair<int, int>>());
            int val = 0;
            for (int j = 0; j < x && j < vec.size(); j++) {
                val += vec[j].first * vec[j].second;
            }
            ans[i] = val;
        }
        return ans;
    }
};