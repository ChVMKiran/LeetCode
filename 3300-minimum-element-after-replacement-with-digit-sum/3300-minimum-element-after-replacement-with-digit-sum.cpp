class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for(int &n: nums) {
            ans = min(ans, n - 9 * (n / 10 + n / 100 + n / 1000 + n / 10000));
            if(ans == 1) break;
        }
        return ans;
    }
};