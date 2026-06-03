class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vec;
        int n = position.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            vec.push_back({position[i], (target - position[i]) / (speed[i] * 1.0)});
        }
        sort(vec.begin(),vec.end());
        while(!vec.empty()) {
            auto [p, t] = vec.back();
            vec.pop_back();
            while(!vec.empty() && vec.back().second <= t) {
                vec.pop_back();
            }
            ans++;
        }
        return ans;
    }
};