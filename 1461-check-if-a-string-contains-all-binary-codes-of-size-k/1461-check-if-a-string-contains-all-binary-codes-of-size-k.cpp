class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> ust;
        for(int i = 0; i <= n - k; i++) {
            ust.insert(s.substr(i, k));
        }
        return ust.size() == (1 << k);
    }
};