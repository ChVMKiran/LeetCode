class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) ump[arr[i]].push_back(i);
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        vis[0] = true;
        while(!qu.empty()) {
            auto [ind, cnt] = qu.front();
            // cout<<ind<<' ';
            if(ind == n - 1) return cnt;
            qu.pop();
            if(ind > 0 && !vis[ind - 1]) {
                qu.push({ind - 1, cnt + 1});
                vis[ind - 1] = true;
            }
            if(ind < n - 1 && !vis[ind + 1]) {
                qu.push({ind + 1, cnt + 1});
                vis[ind + 1] = true;
            }
            for(auto &i: ump[arr[ind]]) {
                if(vis[i]) continue;
                qu.push({i, cnt + 1});
                vis[i] = true;
            }
            ump.erase(arr[ind]);
        }
        return 0;
    }
};