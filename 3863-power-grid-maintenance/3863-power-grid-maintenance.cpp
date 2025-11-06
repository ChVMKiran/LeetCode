class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        vector<vector<int>> adj(c + 1);
        for(auto &conc: connections) {
            adj[conc[0]].push_back(conc[1]);
            adj[conc[1]].push_back(conc[0]);
        }
        vector<int> stationToGrid(c + 1, 0);
        vector<set<int>> gridToStations;
        gridToStations.push_back(set<int> ());
        for(int i = 1, j = 1; i <= c; i++) {
            if(stationToGrid[i]) continue;
            queue<int> qu;
            set<int> st;
            qu.push(i);
            stationToGrid[i] = j;
            st.insert(i);
            while(!qu.empty()) {
                int ele = qu.front();
                qu.pop();
                for(auto &conc: adj[ele]) {
                    if(stationToGrid[conc]) continue;
                    qu.push(conc);
                    st.insert(conc);
                    stationToGrid[conc] = j;
                }
            }
            gridToStations.push_back(st);
            j++;
        }
        for(int i = 0; i < n; i++) {
            if(queries[i][0] == 2) {
                int grid = stationToGrid[queries[i][1]];
                gridToStations[grid].erase(queries[i][1]);
            }
            else {
                int grid = stationToGrid[queries[i][1]];
                if(gridToStations[grid].count(queries[i][1])) ans.push_back(queries[i][1]);
                else if(gridToStations[grid].empty()) ans.push_back(-1);
                else ans.push_back(*(gridToStations[grid].begin()));
            }
        }
        return ans;
    }
};