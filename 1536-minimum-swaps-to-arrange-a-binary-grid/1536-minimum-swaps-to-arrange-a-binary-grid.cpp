class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<int> right0s(n);
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j]) break;
                right0s[i]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(right0s[i] >= n - i - 1) continue;
            int val = right0s[i], j;
            for(j = i + 1; j < n; j++) {
                if(right0s[j] >= n - i - 1) break;
            }
            if(j == n) return -1;
            ans += j - i;
            while(j > i) {
                right0s[j] = right0s[j - 1];
                j--;
            }
        }
        return ans;
    }
};