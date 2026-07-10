class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> parent(n, vector<int> (32));
        vector<int> idx(n), pos(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](const int& i, const int& j) {
            return nums[i] < nums[j];
        });
        for(int i = 0; i < n; i++) {
            pos[idx[i]] = i;
        }
        for(int i = 0, left = 0; i < n; i++) {
            while(nums[idx[i]] - nums[idx[left]] > maxDiff) left++;
            parent[i][0] = left;
        }
        for(int j = 1; j < 32; j++) {
            for(int i = 0; i < n; i++) {
                parent[i][j] = parent[ parent[i][j - 1] ][j - 1];
            }
        }
        int m = queries.size();
        vector<int> ans(queries.size(), -1);
        for(int i = 0; i < m; i++) {
            int u = pos[queries[i][0]], v = pos[queries[i][1]];
            if(u > v) swap(u, v);
            if(u == v) ans[i] = 0;
            else {
                int steps = 0;
                for(int j = 31; j >= 0; j--) {
                    if(parent[v][j] > u) {
                        v = parent[v][j];
                        steps += (1 << j);
                    }
                }
                if(parent[v][0] <= u) ans[i] = steps + 1;
            }
        }
        return ans;
    }
};