class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> st;
        unordered_map<int, int> ump;
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                st.insert(i);
            }
            else {
                ans[i] = -1;
                if(ump.count(rains[i])) {
                    auto it = st.upper_bound(ump[rains[i]]);
                    if(it == st.end()) return {};
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                ump[rains[i]] = i;
            }
        }
        return ans;
    }
};