class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[26] = {0}, vis[26] = {0}, n = s.size();
        string ans;
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < n; i++) {
            if(!vis[s[i] - 'a']) {
                while(!ans.empty() && ans.back() > s[i]) {
                    if(freq[ans.back() - 'a'] == 0) break;
                    else {
                        vis[ans.back() - 'a'] = 0;
                    }
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
            }
            freq[s[i] - 'a']--;
        }
        return ans;
    }
};