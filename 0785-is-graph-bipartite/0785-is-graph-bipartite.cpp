class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int> &colors, int color) {
        colors[node] = color;
        for(int &n: graph[node]) {
            if(colors[n] == -1 && !dfs(graph, n, colors, !color)) return false;
            else if(colors[n] == color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1); // 0 -> greeen, 1 -> yellow
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !dfs(graph, i, colors, 0)) return false;
        }
        return true;
    }
};