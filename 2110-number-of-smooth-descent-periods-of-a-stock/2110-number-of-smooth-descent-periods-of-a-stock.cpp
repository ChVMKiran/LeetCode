class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0, cnt = 1;
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            if(prices[i] == prices[i - 1] - 1) cnt++;
            else {
                ans += (cnt * (cnt + 1) / 2);
                cnt = 1;
            }
        }
        ans += (cnt * (cnt + 1) / 2);
        return ans;
    }
};