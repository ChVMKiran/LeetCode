class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        auto [min1, max1] = ranges::minmax(arr1);
        auto [min2, max2] = ranges::minmax(arr2);
        int lo = min(min1, min2) - d - 1, ans = 0;
        vector<int> freq(max(max1, max2) + d - lo + 1);
        for(int& n: arr2) freq[n - lo]++;
        partial_sum(freq.begin(), freq.end(), freq.begin());
        for(int& n: arr1) {
            ans += (freq[n + d - lo] == freq[n - d - 1 - lo]);
        }
        return ans;
    }
};