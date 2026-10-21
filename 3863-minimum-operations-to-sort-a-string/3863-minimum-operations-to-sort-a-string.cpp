class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string tar = s;
        ranges::sort(tar);
        if(tar == s) return 0;
        if(n == 2) return -1;
        if(tar[0] == s[0] || tar.back() == s.back()) return 1;
        string dup = s;
        sort(s.begin(), s.begin() + n - 1);
        sort(s.begin() + 1, s.end());
        sort(dup.begin() + 1, dup.end());
        sort(dup.begin(), dup.begin() + n - 1);
        if(s == tar || dup == tar) return 2;
        return 3;
    }
};