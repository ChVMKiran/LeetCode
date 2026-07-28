class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int freq[26] = {0};
        for(int i = 0; i < n / 2; i++) freq[s[i] - 'a']++;
        string ans;
        for(int i = 0; i < 26; i++) {
            if(!freq[i]) continue;
            ans += string(freq[i], i + 'a');
        }
        if(n % 2) ans += s[n / 2];
        ans += ans;
        if(n % 2) ans.pop_back();
        reverse(ans.begin() + n / 2 + n % 2, ans.end());
        return ans;
    }
};