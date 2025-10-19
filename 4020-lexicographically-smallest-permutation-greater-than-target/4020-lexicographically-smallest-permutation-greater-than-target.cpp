class Solution {
public:
    string rec(int ind, string t, vector<int>& freq, string curr, bool flag) {
        if(ind == t.size()) {
            if(flag) return curr;
            return "";
        }
        char st = t[ind];
        if(flag) st = 'a';
        for(char ch = st; ch <= 'z'; ch++) {
            if(freq[ch - 'a']) {
                freq[ch - 'a']--;
                curr.push_back(ch);
                string res = rec(ind + 1, t, freq, curr, flag || t[ind] < curr.back());
                if(res != "") return res;
                freq[ch - 'a']++;
                curr.pop_back();
            }
        }
        return "";
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        return rec(0, target, freq, "", false);
    }
};