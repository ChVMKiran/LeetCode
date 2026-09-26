class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> ump;
        for(auto& kv: knowledge) ump[kv[0]] = kv[1];
        int n = s.size();
        string res;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                i++;
                string key;
                while(s[i] != ')') key += s[i++];
                auto it = ump.find(key);
                if(it != ump.end()) res += it->second;
                else res += '?';
            }
            else res += s[i];
        }
        return res;
    }
};