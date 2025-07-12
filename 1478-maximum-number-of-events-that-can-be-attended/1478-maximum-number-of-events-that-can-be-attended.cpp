class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size(), cnt = 0, maxEnd = events[0][1];
        for(int i = 0; i < n; i++) {
            maxEnd = max(maxEnd, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1, j = 0; i <= maxEnd; i++) {
            while(j < n && events[j][0] == i) pq.push(events[j++][1]);
            while(!pq.empty() && pq.top() < i) pq.pop();
            if(!pq.empty()) {
                cnt++;
                pq.pop();
            }
        }
        return cnt;
    }
};