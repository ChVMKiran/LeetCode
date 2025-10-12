class Solution {
public:
    bool allEqual(vector<int>& freq) {
        int val = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                val = freq[i];
                break;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0 && freq[i] != val) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size(), ans = 1;
        int a_count = 0, b_count = 0, c_count = 0;
        vector<int> freq(26);
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            int j = 0;
            if(allEqual(freq)) ans = max(ans, i - j + 1);
            else {
                vector<int> dup = freq;
                while(j < i) {
                    dup[s[j++] - 'a']--;
                    if(allEqual(dup)) ans = max(ans, i - j + 1);
                }
            }
        }
        return ans;
    }
};