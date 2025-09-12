class Solution {
public:
    bool doesAliceWin(string s) {
        int c = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                c++;
            }
        }
        return c != 0;
    }
};