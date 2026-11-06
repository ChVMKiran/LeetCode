class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<vector<int>> q(m);
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            q[i] = {queries[i], i};
        }
        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), [&](const vector<int>& log1, const vector<int>& log2) {
            return log1[1] < log2[1];
        });
        int l = logs.size(), i = 0, j = 0;
        unordered_map<int, int> ump;
        for(int k = 0; k < m; k++) {
            int st = q[k][0] - x, end = q[k][0];
            while(i < l && logs[i][1] < st) {
                if(i < j) {
                    if(--ump[logs[i][0]] == 0) ump.erase(logs[i][0]);
                }
                i++;
            }
            while(j < l && logs[j][1] <= end) {
                if(j >= i) ump[logs[j][0]]++; 
                j++;
            }
            res[q[k][1]] = n - ump.size();
        }
        return res;
    }
};