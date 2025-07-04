class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        unordered_set<string> seen;
        string curr = "";
        for(int i = 0; i < s.size(); i++) {
            curr += s[i];
            if(!seen.count(curr)) {
                seen.insert(curr);
                ans.push_back(curr);
                curr = ""; 
            }
        }
        return ans;
    }
};