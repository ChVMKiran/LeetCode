class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> currMeetings;
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for(int i = 0; i < n; i++) availableRooms.push(i);
        vector<int> freq(n, 0);
        for(auto& meeting : meetings) {
            while(!currMeetings.empty() && currMeetings.top().first <= meeting[0]) {
                availableRooms.push(currMeetings.top().second);
                currMeetings.pop();
            }
            long val = 0;
            if(availableRooms.empty()) {
                availableRooms.push(currMeetings.top().second);
                val = currMeetings.top().first - meeting[0];
                currMeetings.pop();
            }
            currMeetings.emplace(meeting[1] + val, availableRooms.top());
            freq[availableRooms.top()]++;
            availableRooms.pop();
        }
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(freq[ans] < freq[i]) ans = i;
        }
        return ans;
    }
};