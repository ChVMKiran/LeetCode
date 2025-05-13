class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26);
        for(int i = s.size() - 1; i >= 0; i--) freq[s[i] - 'a']++;
        int ans = 0, mod = 1e9 + 7;
        while(t--) {
            int z = freq[25];
            for(int i = 24; i >= 0; i--) {
                freq[i + 1] = freq[i];
            }
            freq[0] = z;
            freq[1] = (freq[1] + z) % mod;
        }
        for(int i = 0; i < 26; i++) {
            ans = (ans + freq[i]) % mod;
        }
        return ans;
    }
};