class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), startInd = 0, minLen = INT_MAX, left = 0, rqrd = n;
        vector<int> mpp(58);
        for(int i = 0; i < n; i++) {
            mpp[t[i] - 'A']++;
        }
        for(int right = 0; right < m; right++) {
            if(mpp[s[right] - 'A']-- > 0) rqrd--;
            while(!rqrd) {
                // cout<<right;
                if(minLen > right - left + 1) {
                    minLen = right - left + 1;
                    startInd = left;
                }
                if(mpp[s[left++] - 'A']++ == 0) rqrd++;
            }
        }
        // cout<<startInd;
        return minLen == INT_MAX ? "" : s.substr(startInd, minLen);
    }
};