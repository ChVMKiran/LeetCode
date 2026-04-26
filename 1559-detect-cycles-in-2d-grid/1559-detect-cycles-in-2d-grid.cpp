class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) {
            return true; //cycle found
        }
        if(rank[a] <= rank[b]) parent[a] = b;
        else parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return false;
    }
    int find(int a) {
        if(parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    ~UnionFind() {
        parent.resize(0);
        rank.resize(0);
    }
};
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m - 1 && grid[i + 1][j] == grid[i][j]) {
                    if(uf.unite((i + 1) * n + j, i * n + j)) return true;
                }
                if(j < n - 1 && grid[i][j] == grid[i][j + 1]) {
                    if(uf.unite(i * n + j, i * n + j + 1)) return true;
                }
            }
        }
        return false;
    }
};