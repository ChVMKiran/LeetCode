class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> res(m);
        vector<int> ids(queries.size());
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(),
             [&](int i, int j) { return queries[i] < queries[j]; });
        sort(logs.begin(), logs.end(), [&](const vector<int>& log1, const vector<int>& log2) {
            return log1[1] < log2[1];
        });
        int l = logs.size(), i = 0, j = 0, cnt = 0;
        int ump[100001]{};
        for(int k = 0; k < m; k++) {
            int st = queries[ids[k]] - x, end = queries[ids[k]];
            while(i < l && logs[i][1] < st) {
                if(i < j) {
                    if(--ump[logs[i][0]] == 0) cnt--;
                }
                i++;
            }
            while(j < l && logs[j][1] <= end) {
                if(j >= i) {
                    if(++ump[logs[j][0]] == 1) cnt++;
                }
                j++;
            }
            res[ids[k]] = n - cnt;
        }
        return res;
    }
};