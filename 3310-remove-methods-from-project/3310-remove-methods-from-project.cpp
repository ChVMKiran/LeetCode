class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> indegree(n);
        bitset<100001> suspicious(0);
        vector<vector<int>> adj(n);
        for(auto& i: invocations) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int> ans;
        queue<int> qu;
        qu.push(k);
        suspicious.set(k);
        while(!qu.empty()) {
            int e = qu.front();
            qu.pop();
            for(int& nn: adj[e]) {
                indegree[nn]--;
                if(suspicious.test(nn)) continue;
                qu.push(nn);
                suspicious.set(nn);
            }
        }
        for(int i = 0; i < n; i++) {
            if(suspicious.test(i) && indegree[i] > 0) {
                ans.resize(n);
                iota(ans.begin(), ans.end(), 0);
                break;
            }
            else if(!suspicious.test(i)) ans.push_back(i);
        }
        return ans;
    }
};