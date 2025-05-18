class Solution {
public:
    int partitionString(string s) {
        vector<bool> freq(26);
        int n = s.size(), cnt = 1;
        for(int i = 0; i < n; i++) {
            if(freq[s[i] - 'a']) {
                cnt++;
                fill(freq.begin(), freq.end(), false);
            }
            freq[s[i] - 'a'] = true;
        }
        return cnt;
    }
};