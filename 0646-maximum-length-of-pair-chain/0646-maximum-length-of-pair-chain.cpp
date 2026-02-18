class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), prevStart = pairs[0][0], prevEnd = pairs[0][1], ans = 1;
        for(int i = 1; i < n; i++) {
            if(prevEnd < pairs[i][0]) {
                ans++;
                prevStart = pairs[i][0];
                prevEnd = pairs[i][1];
            }
            else if(prevEnd > pairs[i][1]) {
                prevStart = pairs[i][0];
                prevEnd = pairs[i][1];
            }
        }
        return ans;
    }
};