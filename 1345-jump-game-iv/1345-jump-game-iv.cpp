class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        vector<int> cost(n, INT_MAX);
        for(int i = 0; i < n; i++) ump[arr[i]].push_back(i);
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        cost[0] = 0;
        while(!qu.empty()) {
            auto [ind, cnt] = qu.front();
            if(ind == n - 1) return cnt;
            qu.pop();
            if(ind > 0 && cost[ind - 1] >= cnt + 1) {
                qu.push({ind - 1, cnt + 1});
                cost[ind - 1] = cnt + 1;
            }
            if(ind < n - 1 && cost[ind + 1] >= cnt + 1) {
                qu.push({ind + 1, cnt + 1});
                cost[ind + 1] = cnt + 1;
            }
            for(auto &i: ump[arr[ind]]) {
                if(cost[i] <= cnt + 1) continue;
                qu.push({i, cnt + 1});
                cost[i] = cnt + 1;
            }
            ump.erase(arr[ind]);
        }
        return 0;
    }
};