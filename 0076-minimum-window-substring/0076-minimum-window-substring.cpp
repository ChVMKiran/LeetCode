class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        vector<int> uppers(26), lowers(26);
        int m = s.size(), n = t.size(), st = 0;
        for(int i = 0; i < n; i++) {
            if(t[i] <= 'Z') uppers[t[i] - 'A']++;
            else lowers[t[i] - 'a']++;
        }
        for(int i = 0; i < m; i++) {
            if(s[i] <= 'Z') uppers[s[i] - 'A']--;
            else lowers[s[i] - 'a']--;
            bool flag = true;
            for(int j = 0; j < 26; j++) {
                if(uppers[j] > 0 || lowers[j] > 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                // cout<<res;
                int k = st;
                while(st <= i) {
                    if(s[st] <= 'Z'){
                        if(!uppers[s[st] - 'A']) break;
                        uppers[s[st] - 'A']++;
                    }
                    else {
                        if(!lowers[s[st] - 'a']) break;
                        lowers[s[st] - 'a']++;
                    }
                    st++;
                }
                if(!res.size() || res.size() > i - st + 1)
                    res = s.substr(st, i - st + 1);
            }
        }
        // cout<<st;
        return res;
    }
};