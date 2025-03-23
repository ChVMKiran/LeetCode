class Solution {
private:
    pair<int, int> dfs(vector<vector<int>>& adj, int ind, vector<bool> &vis) {
        int noOfNodes = 1, noOfEdges = adj[ind].size();
        vis[ind] = true;
        for(int& i: adj[ind]) {
            if(vis[i]) continue;
            pair<int, int> p = dfs(adj, i, vis);
            noOfNodes += p.first;
            noOfEdges += p.second;
        }
        return {noOfNodes, noOfEdges};
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        int count = 0;
        for(auto& i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            pair<int, int> p = dfs(adj, i, vis);
            if(p.first * (p.first - 1) == p.second) count++;
        }
        return count;
    }
};