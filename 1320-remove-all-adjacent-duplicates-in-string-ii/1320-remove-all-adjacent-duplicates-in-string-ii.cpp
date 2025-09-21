class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> lastCharFreq; // stores the consecutive freq of ans.back()
        int n = s.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(lastCharFreq.empty() || ans.back() != s[i]) {
                lastCharFreq.push_back(1);
                ans += s[i];
            }
            else {
                lastCharFreq[lastCharFreq.size() - 1]++;
                ans += s[i];
                if(lastCharFreq.back() == k) {
                    int j = k;
                    while(j--) ans.pop_back();
                    lastCharFreq.pop_back();
                }
            }
        }
        return ans;
    }
};