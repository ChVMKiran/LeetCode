class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int evens[26] = {0}, odds[26] = {0}, n = s1.size();
        for(int i = 0; i < n; i++) {
            if(i % 2) {
                odds[s1[i] - 'a']++;
                odds[s2[i] - 'a']--;
            }
            else {
                evens[s1[i] - 'a']++;
                evens[s2[i] - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(odds[i] || evens[i]) return false;
        }
        return true;
    }
};