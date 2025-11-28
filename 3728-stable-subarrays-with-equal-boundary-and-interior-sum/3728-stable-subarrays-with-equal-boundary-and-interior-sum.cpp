class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        int n = c.size();
        long long ans = 0, pre = 0;
        unordered_map<long long, unordered_map<int, long long>> ump;
        // prefix sum -> (ele -> count)
        for(int i = 0; i < n; i++) {
            if(ump.count(pre - c[i]) && ump[pre - c[i]].count(c[i])) 
                ans += ump[pre - c[i]][c[i]];
            if(i && !c[i] && !c[i - 1]) ans--;
            pre += c[i];
            ump[pre][c[i]]++;
        }
        return ans;
    }
};