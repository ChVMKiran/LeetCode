class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string aux = s + s;
        return aux.find(goal) != string::npos;
    }
};