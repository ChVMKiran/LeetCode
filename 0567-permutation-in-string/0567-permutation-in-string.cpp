class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> ump;
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        for(int i = 0; i < m; i++) ump[s1[i]]++;
        int unq = ump.size(), cnt = 0;
        for(int i = 0; i < m; i++) {
            if(--ump[s2[i]] == 0) cnt++;
        }
        if(cnt == unq) return true;
        for(int i = m; i < n; i++) {
            if(--ump[s2[i]] == 0) cnt++;
            if(ump[s2[i - m]]++ == 0) cnt--;
            if(cnt == unq) return true;
        }
        return false;
    }
};