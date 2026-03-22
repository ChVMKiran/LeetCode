class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bitset<4> flag = 15; //1111
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                flag[0] = flag[0] & (mat[i][j] == target[i][j]); //0
                flag[1] = flag[1] & (mat[n - j - 1][i] == target[i][j]); //90
                flag[2] = flag[2] & (mat[n - i - 1][n - j - 1] == target[i][j]); //180
                flag[3] = flag[3] & (mat[j][n - i - 1] == target[i][j]); //270
            }
            if(flag == 0) return false;
        }
        return true;
    }
};
