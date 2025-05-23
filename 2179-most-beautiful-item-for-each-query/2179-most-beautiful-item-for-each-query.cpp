class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> ans(m);
        sort(items.begin(), items.end());
        for(int i = 1; i < n; i++) {
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        for(int i = 0; i < m; i++) {
            if(queries[i] < items[0][0]) continue;
            int low = 0, high = n - 1;
            while(low < high) {
                int mid = low + ((high - low) >> 1);
                if(items[mid][0] <= queries[i]) low = mid + 1;
                else high = mid;
            }
            // if(low != high) return vector<int>(m, -1);
            if(items[low][0] > queries[i]) ans[i] = items[low - 1][1];
            else ans[i] = items[low][1];
        }
        return ans;
    }
};