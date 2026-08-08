class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(n == 1) return {0};
        vector<int> suff(m);
        for(int i = m - 1, j = n - 1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j]) j--, suff[i]++;
            if(i < m - 1) suff[i] += suff[i + 1];
        }
        vector<int> ans;
        bool flag = true;
        for(int i = 0, j = 0; i < m && j < n; i++) {
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if(flag && (i == m - 1 || suff[i + 1] >= n - j - 1)) {
                ans.push_back(i);
                j++;
                flag = false;
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};