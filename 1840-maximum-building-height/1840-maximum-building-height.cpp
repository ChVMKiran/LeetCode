class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end());
        int pi = 1, ph = 0;
        int m = restrictions.size(), ans = 0;
        for(int i = 0; i < m; i++) {
            int ci = restrictions[i][0], ch = restrictions[i][1];
            ch = min(ch, ph + ci - pi);
            restrictions[i] = {ci, ch};
            pi = ci;
            ph = ch;
        }
        ans = ph + n - pi;
        for(int i = m - 2; i >= 0; i--) {
            int ci = restrictions[i][0], ch = restrictions[i][1];
            ch = min(ch, ph + pi - ci);
            restrictions[i] = {ci, ch};
            pi = ci;
            ph = ch;
            ans = max(ans, ch);
        }
        pi = 1, ph = 0;
        for(int i = 0; i < m; i++) {
            int dist = restrictions[i][0] - pi - 1;
            int ci = restrictions[i][0], ch = restrictions[i][1];
            ans = max(ans, max(ch, ph) + (dist - abs(ch - ph) + 1) / 2);
            pi = ci, ph = ch;
        }
        return ans;
    }
};