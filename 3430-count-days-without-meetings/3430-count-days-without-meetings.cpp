class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int count = meetings[0][0] - 1, n = meetings.size(), prevEnd = meetings[0][1];
        for(int i = 1; i < n; i++) {
            if(prevEnd < meetings[i][0]) count += meetings[i][0] - prevEnd - 1;
            prevEnd = max(prevEnd, meetings[i][1]);
        }
        count += days - prevEnd;
        return count;
    }
};