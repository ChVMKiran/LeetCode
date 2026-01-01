class Solution {
public:
    int m, n;
    bool helper(int row, int col, int ind, vector<vector<char>>& board, string& word) {
        if(ind == word.size()) return true;

            if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[ind]) return false;

            char tmp = board[row][col];
            board[row][col] = '#';

            if(helper(row - 1, col, ind + 1, board, word)) return true;
            if(helper(row + 1, col, ind + 1, board, word)) return true;
            if(helper(row, col - 1, ind + 1, board, word)) return true;
            if(helper(row, col + 1, ind + 1, board, word)) return true;

            board[row][col] = tmp;
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        unordered_map<char, int> ump;
        for (auto& r : board) {
            for (char& c : r) {
                ump[c]++;
            }
        }

        if(ump[word[0]] > ump[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for(char& c : word) {
            if(--ump[c] < 0) return false;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && helper(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};