class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int len = buildings.size(), ans = 0;
        unordered_map<int, int> rowsMin;
        unordered_map<int, int> rowsMax;
        unordered_map<int, int> colsMin;
        unordered_map<int, int> colsMax;
        for(int i = 0; i < len; i++) {
            int row = buildings[i][0], col = buildings[i][1];
            if(rowsMin.count(row)) {
                rowsMin[row] = min(rowsMin[row], col);
                rowsMax[row] = max(rowsMax[row], col);
            }
            else {
                rowsMin[row] = col;
                rowsMax[row] = col;
            }
            if(colsMin.count(col)) {
                colsMin[col] = min(colsMin[col], row);
                colsMax[col] = max(colsMax[col], row);
            }
            else {
                colsMin[col] = row;
                colsMax[col] = row;
            }
        }
        for(int i = 0; i < len; i++) {
            int row = buildings[i][0], col = buildings[i][1];
            if(rowsMin[row] == col) continue;
            if(colsMin[col] == row) continue;
            if(rowsMax[row] == col) continue;
            if(colsMax[col] == row) continue;
            ans++;
        }
        return ans;
    }
};