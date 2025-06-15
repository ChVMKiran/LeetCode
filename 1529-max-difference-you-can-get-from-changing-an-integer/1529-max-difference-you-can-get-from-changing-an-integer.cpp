class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num), t = s;
        int ind = s.find_first_not_of('9');
        char ch;
        if(ind != -1) { 
            ch = s[ind];
            replace(s.begin(), s.end(), ch, '9');
        }
        int ind1 = -1;
        for(int i = 0; i < t.size(); i++) {
            if(t[i] > '1') {
                ind1 = i;
                break;
            }
        }
        if(ind1 != -1) {
            ch = t[ind1];
            char val = '1';
            if(ind1 != 0) val = '0';
            replace(t.begin(), t.end(), ch, val);
        }
        return stoi(s) - stoi(t);
    }
};