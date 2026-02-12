class Solution {
public:
    bool isBal(vector<int>& freq) {
        int val = -1;
        for(int i = 0; i < 26; i++) {
            if(!freq[i]) continue;
            if(val == -1) val = freq[i];
            else if(val != freq[i]) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size(), ans = 1;
        for(int i = 0; i < n; i++) {
            vector<int> freq(26);
            for(int j = i; j < n; j++) {
                if(ans >= n - i) break;
                freq[s[j] - 'a']++;
                if(isBal(freq)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};