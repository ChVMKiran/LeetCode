class Solution {
private:
    int chvmkiran(int i1, int j1, int k,vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<int> vec(k * k);
        for(int i = i1, ind = 0; i < i1 + k; i++) {
            for(int j = j1; j < j1 + k; j++, ind++) {
                vec[ind] = grid[i][j];
            }
        }
        sort(vec.begin(),vec.end());
        for(int i = 0; i < k * k - 1; i++) {
            if(vec[i] != vec[i + 1]) ans = min(ans, vec[i + 1] - vec[i]);
        }
        return ans == INT_MAX ? 0: ans;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int> (n - k + 1, 0));
        if(k == 1) return res;
        for(int i = 0; i < m - k + 1; i++) {
            for(int j = 0; j < n - k + 1; j++) {
                res[i][j] = chvmkiran(i, j, k, grid);
            }
        }
        return res;
    }
};