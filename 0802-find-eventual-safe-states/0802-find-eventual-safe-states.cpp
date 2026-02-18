class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outdegree(n);
        vector<int> ans;
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            for(auto& node: graph[i]) {
                adj[node].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if(outdegree[i] == 0) {
                qu.push(i);
            }
        }
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for(auto& nn: adj[node]) {
                outdegree[nn]--;
                if(outdegree[nn] == 0) {
                    qu.push(nn);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(outdegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};