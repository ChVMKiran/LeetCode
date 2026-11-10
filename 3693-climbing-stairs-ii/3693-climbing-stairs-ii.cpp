class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++) {
            int val = min({a + costs[i] + 1, b + costs[i] + 4, c + costs[i] + 9});
            c = b;
            b = a;
            a = val;
        }
        return a;
    }
};