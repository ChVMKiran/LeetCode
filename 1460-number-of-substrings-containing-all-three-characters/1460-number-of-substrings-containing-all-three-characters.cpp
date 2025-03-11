class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, n = s.size(), j = 0;
        unordered_map<char, int> ump = {
            {'a', 0},
            {'b', 0},
            {'c', 0}
        };
        for(int i = 0; i < n; i++) {
            ump[s[i]]++;
            while(ump['a'] && ump['b'] && ump['c']) {
                count += n - i;
                if(ump[s[j]]) ump[s[j]]--;
                j++;
            }
        }
        return count;
    }
};