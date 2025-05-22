class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for(int i = 0; i < m; i++) {
            int right = n - 1;
            for(int left = n - 1; left >= 0; left--) {
                if(boxGrid[i][left] == '#') {
                    ans[right][m - 1 - i] = '#';
                    if(left != right) ans[left][m - 1 - i] = '.';
                    right--;
                    continue;
                }
                else if(boxGrid[i][left] == '*') right = left - 1;
                ans[left][m - 1 - i] = boxGrid[i][left];
            }
        }
        return ans;
    }
};