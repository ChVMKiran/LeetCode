class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int curr = 0, n = costs.size();
        sort(costs.begin(), costs.end());
        for(int i = 0; i < n; i++) {
            curr += costs[i];
            if(curr > coins) return i;
        }
        return n;
    }
};