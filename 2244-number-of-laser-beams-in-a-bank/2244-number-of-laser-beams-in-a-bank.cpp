class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0, n = bank.size();
        for(int i = 0; i < n; i++) {
            int curr = count(bank[i].begin(),bank[i].end(), '1');
            ans += prev * curr;
            if(curr) prev = curr;
        }
        return ans;
    }
};