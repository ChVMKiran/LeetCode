class Solution {
public:
    bool helper(vector<vector<char>>& board,vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& grids) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(int num = 1; num <= 9; num++) {
                        if(rows[i][num - 1] || cols[j][num - 1] || grids[(i / 3) * 3 + j / 3][num - 1])
                            continue;
                        board[i][j] = num + '0';
                        rows[i][num - 1] = true;
                        cols[j][num - 1] = true;
                        grids[(i / 3) * 3 + j / 3][num - 1] = true;
                        if(helper(board, rows, cols, grids)) 
                            return true;
                        board[i][j] = '.';
                        rows[i][num - 1] = false;
                        cols[j][num - 1] = false;
                        grids[(i / 3) * 3 + j / 3][num - 1] = false;
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> grids(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                rows[i][board[i][j] - '1'] = true;
                cols[j][board[i][j] - '1'] = true;
                grids[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
            }
        }
        helper(board, rows, cols, grids);
    }
};