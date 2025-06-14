class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), t = s;
        int ind = s.find_first_not_of('9');
        char ch;
        if(ind != -1) { 
            ch = s[ind];
            replace(s.begin(), s.end(), ch, '9');
        }
        ch = t[0];
        replace(t.begin(), t.end(), ch, '0');
        return stoi(s) - stoi(t);
    }
};