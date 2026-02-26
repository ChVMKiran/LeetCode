class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> vals(n);
        int fact = 1;
        for(int i = 0; i < n; i++) {
            vals[i] = i + 1;
            fact *= (i + 1);
        }
        while(vals.size() > 1) {
            int block = ceil((k * n) / (fact * 1.0)) - 1;
            ans += (vals[block] + '0');
            vals.erase(vals.begin() + block);
            k -= block * (fact / n);
            fact /= (vals.size());
        }
        ans += (vals.back() + '0');
        return ans;
    }
};