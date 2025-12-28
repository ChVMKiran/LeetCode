class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<int> suffMax(n);
        suffMax[n - 1] = events[n - 1][2];
        for(int i = n - 2; i >= 0; i--) suffMax[i] = max(events[i][2], suffMax[i + 1]);
        int ans = suffMax[0];
        for(int i = 0; i < n - 1; i++) {
            int low = i + 1, high = n - 1;
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(events[mid][0] > events[i][1]) high = mid;
                else low = mid + 1;
            }
            if(events[low][0] > events[i][1]) ans = max(ans, suffMax[low] + events[i][2]);
        }
        return ans;
    }
};