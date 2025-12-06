class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        int ind = 0, n = prerequisites.size();
        for(auto &pr: prerequisites) {
            indegree[pr[0]]++;
            adj[pr[1]].push_back(pr[0]);
        }
        queue<int> qu;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) qu.push(i);
        }
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            ind++;
            for(int n: adj[node]) {
                indegree[n]--;
                if(indegree[n] == 0) qu.push(n);
            }
        }
        return ind == numCourses;
    }
};