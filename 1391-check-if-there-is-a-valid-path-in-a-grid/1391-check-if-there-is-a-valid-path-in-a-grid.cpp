class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        // rank.resize(n, 0);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        parent[b] = a;
    }
    int find(int a) {
        if(parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    ~UnionFind() {
        parent.resize(0);
    }
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                switch(grid[i][j]) {
                    case 1:
                        if(j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                            uf.unite(i * n + j, i * n + j + 1);
                        }
                        break;
                    case 2:
                        if(i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)) {
                            uf.unite(i * n + j, (i + 1) * n + j);
                        }
                        break;
                    case 3:
                        if(i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)) {
                            uf.unite(i * n + j, (i + 1) * n + j);
                        }
                        break;
                    case 4:
                        if(i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6)) {
                            uf.unite(i * n + j, (i + 1) * n + j);
                        }
                        if(j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                            uf.unite(i * n + j, i * n + j + 1);
                        }
                        break;
                    case 6:
                        if(j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5)) {
                            uf.unite(i * n + j, i * n + j + 1);
                        }
                        break;
                }
            }
        }
        return uf.find(0) == uf.find(m * n - 1);
    }
};