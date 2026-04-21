class Solution {
private:
    vector<int> rank, parent;
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return;

        if(rank[i] < rank[j]) parent[i] = j;
        else parent[j] = i;

        if(rank[i] == rank[j]) rank[i]++;
    }
    int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto &s: allowedSwaps) {
            unite(s[0], s[1]);
        }
        unordered_map<int, unordered_map<int, int>> ump;
        for(int i = 0; i < n; i++) {
            ump[find(i)][source[i]]++;
        }
        for(int i = 0; i < n; i++) {
            int p = find(i);
            if(ump[p][target[i]]) ump[p][target[i]]--;
            else ans++;
        }
        return ans;
    }
};