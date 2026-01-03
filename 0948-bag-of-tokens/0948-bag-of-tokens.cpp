class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans = 0, curr = 0, l = 0, h = tokens.size() - 1;
        while(l <= h) {
            if(power >= tokens[l]) {
                curr++;
                power -= tokens[l++];
                ans = max(ans, curr);
            }
            else if(ans) {
                curr--;
                power += tokens[h--];
            }
            else break;
        }
        return ans;
    }
};