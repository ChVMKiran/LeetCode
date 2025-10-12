class Solution {
public:
    void twoEquals(string s, char x, char y, char z, int &ans) {
        int n = s.size(), x_count = 0, y_count = 0;
        for(int i = 0; i < n; i++) {
            int left = i;
            unordered_map<int, int> ump;
            while(i < n && s[i] != z) {
                i++;
            }
            int right = i - 1, diff = 0;
            ump[0] = left - 1;
            for(int j = left; j <= right; j++) {
                if(s[j] == x) diff++;
                else if(s[j] == y) diff--;
                if(ump.count(diff)) ans = max(ans, j - ump[diff]);
                else ump[diff] = j;
            }
        }
    }
    int longestBalanced(string s) {
        int n = s.size(), ans = 1, curr = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) curr++;
            else curr = 1;
            ans = max(ans, curr);
        }
        int a_count = 0, b_count = 0, c_count = 0;
        map<tuple<int, int, int>, int> ump;
        ump[{0, 0, 0}] = -1;
        twoEquals(s, 'a', 'b', 'c', ans);
        twoEquals(s, 'b', 'c', 'a', ans);
        twoEquals(s, 'c', 'a', 'b', ans);
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a_count++;
            else if(s[i] == 'b') b_count++;
            else c_count++;
            int mini = min({a_count, b_count, c_count});
            tuple<int, int, int> key = {a_count - mini, b_count - mini, c_count - mini};
            if(ump.count(key)) ans = max(ans, i - ump[key]);
            else ump[key] = i;
        }
        return ans;
    }
};