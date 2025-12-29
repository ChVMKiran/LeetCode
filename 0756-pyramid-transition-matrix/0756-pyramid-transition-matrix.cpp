class Solution {
private:
    int n;
    unordered_set<string> ust;
    unordered_map<string, vector<char>> ump;
    bool fun(string &bottom, int ind, string& next) {
        if(ind == bottom.size() - 1) {
            if(next.size() == 1) return true;
            if(ust.count(next)) return false;
            ust.insert(next);
            string temp;
            return fun(next, 0, temp);
        }
        for(auto &ch : ump[bottom.substr(ind, 2)]) {
            next.push_back(ch);
            if(fun(bottom, ind + 1, next)) return true;
            next.pop_back();
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        n = allowed.size();
        for(auto &s: allowed) ump[s.substr(0,2)].push_back(s[2]);
        for(int i = 0; i + 1 < bottom.size(); i++) {
            if(!ump.count(bottom.substr(0, 2))) return false;
        }
        string temp;
        return fun(bottom, 0, temp);
    }
};