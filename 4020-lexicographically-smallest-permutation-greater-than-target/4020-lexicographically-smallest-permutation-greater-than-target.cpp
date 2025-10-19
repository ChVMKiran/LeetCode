class Solution {
public:
    bool rec(int ind, string &t, vector<int>& freq, string &curr, bool flag) {
        if(ind == t.size()) {
            return flag;
        }
        if(flag) {
            for(int i = 0; i < 26; i++) {
                curr += string(freq[i], 'a' + i);
            }
            return true;
        }
        for(char ch = t[ind]; ch <= 'z'; ch++) {
            if(!freq[ch - 'a']) continue;
            freq[ch - 'a']--;
            curr.push_back(ch);
            if(rec(ind + 1, t, freq, curr, flag || t[ind] < curr.back()))
                return true;
            freq[ch - 'a']++;
            curr.pop_back();
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        string ans;
        if(rec(0, target, freq, ans, false)) return ans;
        return "";
    }
};