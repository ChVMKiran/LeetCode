class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int rem = grid[0][0] % x;
        for(auto& row : grid) {
            for(auto& cell : row) {
                if(rem != cell % x) return -1;
                arr.push_back(cell);
            }
        }
        sort(arr.begin(), arr.end());
        int n = arr.size(), count = (arr[n / 2] - arr[0]) / x;
        for(int i = 1; i < n; i++) {
            count += abs(arr[n / 2] - arr[i]) / x;
        }
        return count;
    }
};