class Solution {
public:
    void rec(int n, vector<string>& ans, int opens, int closes, string curr) {
        if (opens + closes == 2 * n && opens == closes) {
            ans.push_back(curr);
            return;
        }
        if (opens < n)
            rec(n, ans, opens + 1, closes, curr + "(");
        if (opens > closes)
            rec(n, ans, opens, closes + 1, curr + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(n, ans, 0, 0, "");
        return ans;
    }
};