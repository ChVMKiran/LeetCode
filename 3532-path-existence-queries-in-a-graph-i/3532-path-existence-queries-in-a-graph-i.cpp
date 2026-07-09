class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> id(n);
        id[0] = 0;
        for(int i = 1, j = 0; i < n; i++) {
            if(nums[i] - nums[i - 1] > maxDiff) j++;
            id[i] = j;
        }
        int m = queries.size();
        vector<bool> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = (id[queries[i][0]] == id[queries[i][1]]);
        }
        return ans;
    }
};