class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0] % x, l = INT_MAX, r = INT_MIN, freq[10001] = {0};
        for(auto& row : grid) {
            for(auto& num : row) {
                auto [q, rr] = div(num, x);
                if(rr != rem) return -1;
                freq[q]++;
                l = min(l, q);
                r = max(r, q);
            }
        }
        int ans = 0;
        while(l < r) {
            while(l < r && freq[l] == 0) l++;
            while(l < r && freq[r] == 0) r--;
            ans += r - l;
            if(--freq[l] == 0) l++;
            if(--freq[r] == 0) r--;
        }
        return ans;
    }
};
// we are computing steps[arr[i]] - steps[arr[n - i - 1]] where steps[a] = steps to reduce a to grid[0][0] % x 
// it is equivalent to sum(abs(arr[n / 2] - arr[i]))
// arr[m] - arr[0] +...arr[m] - arr[m] + arr[m + 1] - arr[m] +...+ arr[n - 1] - arr[m]
// arr[m] and -arr[m] will be cancelled out