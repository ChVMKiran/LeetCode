class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start] == 0) return true;
        queue<int> qu;
        vector<bool> vis(n);
        vis[start] = true;
        qu.push(start);
        while(!qu.empty()) {
            int ind = qu.front();
            qu.pop();
            int i = ind - arr[ind];
            if(i >= 0 && !vis[i]) {
                if(arr[i] == 0) return true;
                qu.push(i);
                vis[i] = true;
            }
            i = ind + arr[ind];
            if(i < n && !vis[i]) {
                if(arr[i] == 0) return true;
                qu.push(i);
                vis[i] = true;
            }
        }
        return false;
    }
};