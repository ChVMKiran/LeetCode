class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.size();
        for(int maxUniques = 1; maxUniques <= 26; maxUniques++) {
            int currUniques = 0, kFreqs = 0;
            int left = 0, right = 0;
            vector<int> freq(26, 0);
            while(right < n) {
                if(!freq[s[right] - 'a']) currUniques++;
                freq[s[right] - 'a']++;
                if(freq[s[right] - 'a'] == k) kFreqs++;
                while(currUniques > maxUniques) {
                    if(freq[s[left] - 'a'] == k) kFreqs--;
                    freq[s[left] - 'a']--;
                    if(!freq[s[left] - 'a']) currUniques--;
                    left++;
                }
                if(kFreqs == maxUniques) ans = max(ans, right - left + 1);
                right++;
            }
        }
        return ans;
    }
};