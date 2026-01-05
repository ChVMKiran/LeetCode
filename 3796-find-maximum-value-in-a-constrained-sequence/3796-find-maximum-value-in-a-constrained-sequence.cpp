class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> left(n, 1e9);
        left[0] = 0;
        for(auto &restriction: restrictions) {
            left[restriction[0]] = restriction[1];
        }
        for(int i = 1; i < n; i++) {
            left[i] = min(left[i], left[i - 1] + diff[i - 1]);
        }
        int ans = left[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            left[i] = min(left[i], left[i + 1] + diff[i]);
            ans = max(ans, left[i]);
        }
        return ans;
    }
};