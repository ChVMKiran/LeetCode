class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), rem = 1;
        vector<int> res;
        for(int i = n - 1; i >= 0; i--) {
            if(rem == 0) {
                res.push_back(digits[i]);
                continue;
            }
            int val = digits[i] + rem;
            res.push_back(val % 10);
            rem = val / 10;
        }
        if(rem) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};