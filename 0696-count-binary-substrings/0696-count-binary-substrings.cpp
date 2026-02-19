class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; ) {
            char first, second;
            int a = 0, b = 0;
            if(s[i] == '0') first = '0', second = '1';
            else first = '1', second = '0';
            while(i < n && s[i] == first) a++, i++;
            int j = i;
            while(j < n && s[j] == second) b++, j++;
            ans += min(a, b);
        }
        return ans;
    }
};