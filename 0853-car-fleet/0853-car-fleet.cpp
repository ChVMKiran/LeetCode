class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, double>> pq;
        int n = position.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            pq.push({position[i], (target - position[i]) / (speed[i] * 1.0)});
        }
        while(!pq.empty()) {
            auto [p, t] = pq.top();
            // cout<<p<<' '<<t<<endl;
            pq.pop();
            while(!pq.empty() && pq.top().second <= t) {
                // cout<<pq.top().first<<' '<<pq.top().second<<endl;
                pq.pop();
            }
            ans++;
        }
        return ans;
    }
};