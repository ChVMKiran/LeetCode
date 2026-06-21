class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0, n = costs.size(), maxi = 0;
        int freq[100001] = {0};
        for(int &cost: costs) {
            freq[cost]++;
            maxi = max(maxi, cost);
        }
        for(int i = 1; i <= maxi; i++) {
            if(!freq[i]) continue;
            int buy = min(freq[i], coins / i);
            if(!buy) break;
            coins -= buy * i;
            cnt += buy;
        }
        return cnt;
    }
};