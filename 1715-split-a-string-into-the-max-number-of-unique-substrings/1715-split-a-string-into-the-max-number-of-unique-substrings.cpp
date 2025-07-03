class Solution {
public:
    int maxCount = 1;
    void helper(string s, int ind, int count, unordered_set<string>& ust) {
        if(count + s.size() - ind <= maxCount) return;
        if(ind == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }
        for(int i = ind + 1; i <= s.size(); i++) {
            string str = s.substr(ind, i - ind);
            if(ust.find(str) == ust.end()) {
                ust.insert(str);
                helper(s, i, count + 1, ust);
                ust.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> ust;
        helper(s, 0, 0, ust);
        return maxCount;
    }
};