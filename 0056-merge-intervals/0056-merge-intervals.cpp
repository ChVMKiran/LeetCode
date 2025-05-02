class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], end = intervals[0][1];
        for(auto &interval : intervals) {
            if(end < interval[0]) {
                ans.push_back({st, end});
                st = interval[0];
                end = interval[1];
            }
            else end = max(end, interval[1]);
        }
        ans.push_back({st, end});
        return ans;
    }
};