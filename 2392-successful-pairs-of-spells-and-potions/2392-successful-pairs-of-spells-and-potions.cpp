class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            long long val = ceil((success * 1.0) / spells[i]);
            ans[i] = (potions.end() - lower_bound(potions.begin(), potions.end(), val));
        }
        return ans;
    }
};