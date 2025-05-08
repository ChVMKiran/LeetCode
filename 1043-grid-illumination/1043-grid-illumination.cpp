class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        set<pair<int, int>> st;
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        unordered_map<int, int> diagonal1;
        unordered_map<int, int> diagonal2;

        for(auto &lamp :lamps) {
            if(st.find({lamp[0], lamp[1]}) != st.end()) continue;
            
            st.insert({lamp[0], lamp[1]});
            rows[lamp[0]]++;
            cols[lamp[1]]++;
            diagonal1[lamp[0] - lamp[1]]++;
            diagonal2[lamp[0] + lamp[1]]++;
        }

        vector<int> ans(queries.size());
        int i = 0;

        for(auto &q :queries) {
            if(rows[q[0]] > 0 || cols[q[1]] > 0 || 
            diagonal1[q[0] - q[1]] > 0 || diagonal2[q[0] + q[1]] > 0) ans[i] = 1;

            for(int row = q[0] - 1; row <= q[0] + 1; row++) {
                for(int col = q[1] - 1; col <= q[1] + 1; col++) {
                    if(st.find({row, col}) != st.end()) {
                        rows[row]--;
                        cols[col]--;
                        diagonal1[row - col]--;
                        diagonal2[row + col]--;
                        st.erase({row, col});
                    }
                }
            }
            i++;
        }
        return ans;
    }
};