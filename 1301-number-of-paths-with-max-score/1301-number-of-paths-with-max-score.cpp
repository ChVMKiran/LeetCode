class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), mod = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == n - 1 && j == n - 1 || board[i][j] == 'X') continue;
                int score = -1, ways = 0;
                if(i + 1 < n && dp[i + 1][j].first != -1) {
                    if(dp[i + 1][j].first > score) {
                        score = dp[i + 1][j].first;
                        ways = dp[i + 1][j].second;
                    }
                    else if(dp[i + 1][j].first == score) {
                        ways = (ways + dp[i + 1][j].second) % mod;
                    }
                }
                if(j + 1 < n && dp[i][j + 1].first != -1) {
                    if(dp[i][j + 1].first > score) {
                        score = dp[i][j + 1].first;
                        ways = dp[i][j + 1].second;
                    }
                    else if(dp[i][j + 1].first == score) {
                        ways = (ways + dp[i][j + 1].second) % mod;
                    }
                }
                if(i + 1 < n && j + 1 < n && dp[i + 1][j + 1].first != -1) {
                    if(dp[i + 1][j + 1].first > score) {
                        score = dp[i + 1][j + 1].first;
                        ways = dp[i + 1][j + 1].second;
                    }
                    else if(dp[i + 1][j + 1].first == score) {
                        ways = (ways + dp[i + 1][j + 1].second) % mod;
                    }
                }
                if(score == -1) continue;
                dp[i][j] = {score + (i || j ? board[i][j] - '0' : 0), ways % mod};
            }
        }
        if(dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};