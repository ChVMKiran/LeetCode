class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res, freq(26);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a'] = i;
        }
        for(int i = 0; i < n; i++) {
            int start = i, end = freq[s[i] - 'a'];
            while(i < end) {
                end = max(end, freq[s[i++] - 'a']);
            }
            res.push_back(end - start + 1);
        }
        return res;
    }
};