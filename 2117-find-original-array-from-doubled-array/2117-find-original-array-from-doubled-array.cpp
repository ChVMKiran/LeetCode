class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), maxi = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            ump[changed[i]]++;
            maxi = max(maxi, changed[i] / 2);
        }
        vector<int> ans;
        for(int i = 0; i < ump[0] / 2; i++) ans.push_back(0);
        for(int i = 1; i <= maxi; i++) {
            if(ump.count(i) && ump.count(2 * i)) {
                int val = min(ump[i], ump[2 * i]);
                for(int j = 0; j < val; j++) {
                    ump[i]--;
                    ump[2 * i]--;
                    ans.push_back(i);
                }
            }
        }
        return ans.size() * 2 == changed.size() ? ans : vector<int>();
    }
};