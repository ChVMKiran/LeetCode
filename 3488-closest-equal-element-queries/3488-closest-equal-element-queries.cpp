class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, set<int>> ump;
        for(int i = 0; i < n; i++) {
            ump[nums[i]].insert(i);
        }
        vector<int> ans(queries.size(), INT_MAX);
        int ind = 0;
        for(int &i: queries) {
            auto &st = ump[nums[i]];
            if(st.size() == 1) {
                ans[ind++] = -1;
                continue;
            }
            auto it = st.find(i);
            // prev
            if(it == st.begin()) {
                ans[ind] = min(ans[ind], n - *st.rbegin() + i);
            }
            else {
                ans[ind] = min(ans[ind], i - *prev(it));
            }
            // next
            if(next(it) == st.end()) {
                ans[ind] = min(ans[ind], n - i + *st.begin());
            }
            else {
                ans[ind] = min(ans[ind], *next(it) - i);
            }
            ind++;
        }
        return ans;
    }
};