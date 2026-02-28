class Solution {
public:
    bool helper(string s, string p, int i, int j, vector<vector<int>> &memo) {
        if(i == -1 && j == -1) return true;
        if(j == -1) return false;
        if(i == -1) {
            while(j >= 0 && p[j] == '*') j -= 2;
            return j == -1;
        }
        if(memo[i][j] != -1) return memo[i][j];
        if(p[j] == '.' || s[i] == p[j]) {
            if(helper(s, p, i - 1, j - 1, memo)) return memo[i][j] = 1;
        }
        if(p[j] == '*') {
            char m = p[j - 1];
            if(helper(s, p, i, j - 2, memo)) return memo[i][j] = 1;
            for(int k = i; k >= 0 && (s[k] == m || m == '.'); k--) {
                if(helper(s, p, k - 1, j - 2, memo)) return memo[i][j] = 1;
            }
        }
        return memo[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return helper(s, p, s.size() - 1, p.size() - 1, memo);
    }
};