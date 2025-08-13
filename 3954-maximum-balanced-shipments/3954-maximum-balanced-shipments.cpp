class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt = 0, maxi = weight[0], n = weight.size();
        for(int i = 1; i < n; i++) {
            if(maxi > weight[i]) {
                cnt++;
                if(i != n - 1) {
                    maxi = weight[i + 1];
                }
            }
            else maxi = weight[i];
        }
        return cnt;
    }
};