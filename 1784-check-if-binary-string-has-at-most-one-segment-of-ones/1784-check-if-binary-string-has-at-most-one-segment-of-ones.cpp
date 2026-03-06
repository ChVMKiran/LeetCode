class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; s[i]; i++) {
            if(s[i] == '1' && s[i - 1] != '1') return false;
        }
        return true;
    }
};