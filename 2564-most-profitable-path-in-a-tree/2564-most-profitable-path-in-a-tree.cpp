class Solution {
public:
    vector<int>dist;
    vector<vector<int>>tree;
    int n;
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size();
        dist.resize(n);
        tree.resize(n,vector<int>());
        for (vector<int>&v:edges) {
            tree[v[0]].push_back(v[1]);
            tree[v[1]].push_back(v[0]);
        }
        return findPaths(0, 0, 0, bob, amount);
    }

private:
    int findPaths(int source, int parent, int time, int bob, vector<int>& amount) {
        int ans = 0, maxi = INT_MIN;
        if (source == bob)
            dist[source] = 0;
        else
            dist[source] = n;
        for (int adj : tree[source]) {
            if (adj != parent) {
                maxi = max(maxi, findPaths(adj, source, time + 1, bob,amount));
                dist[source] = min(dist[source],dist[adj] + 1);
            }
        }
        if (dist[source] > time) ans += amount[source];
        else if (dist[source] == time)
            ans += amount[source] / 2;
        if (maxi == INT_MIN)
            return ans;
        else
            return ans + maxi;
    }
};