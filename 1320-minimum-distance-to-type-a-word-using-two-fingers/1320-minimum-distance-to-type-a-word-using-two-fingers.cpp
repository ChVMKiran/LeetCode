class Solution {
public:
    int dist(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(26, 0);
        for(int i = 1; i < n; i++) {
            vector<int> ndp(26, INT_MAX);
            int prev = word[i - 1] - 'A', curr = word[i] - 'A';
            int d = dist(prev, curr);
            for(int j = 0; j < 26; j++) {
                ndp[j] = min(ndp[j], dp[j] + d);
            }
            for(int j = 0; j < 26; j++) {
                ndp[prev] = min(ndp[prev], dp[j] + dist(curr, j));
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};