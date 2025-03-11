class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, n = s.size(), j = 0;
        unordered_map<char, int> ump;
        for(int i = 0; i < n; i++) {
            ump[s[i]]++;
            while(ump.size() == 3) {
                count += n - i;
                ump[s[j]]--;
                if(ump[s[j]] == 0) ump.erase(s[j]);
                j++;
            }
        }
        return count;
    }
};