class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = neededTime.size(), prev = neededTime[0];
        for(int i = 1; i < n; i++) {
            if(colors[i] == colors[i - 1]) {
                ans += min(neededTime[i], prev);
                if(neededTime[i] < prev) continue;
            }
            prev = neededTime[i];
        }
        return ans;
    }
};