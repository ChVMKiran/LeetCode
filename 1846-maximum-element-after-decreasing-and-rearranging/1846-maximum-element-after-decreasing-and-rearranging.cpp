class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 1, n = arr.size(), maxi = 1;
        vector<int> ump(n + 1);
        for(int i = 0; i < n; i++)  ump[min(n, arr[i])]++;
        for(int i = 2; i <= n; i++) {
            ans = min(ans + ump[i], i);
        }
        return ans;
    }
};