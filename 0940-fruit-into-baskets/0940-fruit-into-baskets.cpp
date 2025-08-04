class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, n = fruits.size();
        unordered_map<int, int> ump;
        for(int i = 0, j = 0; i < n; i++) {
            ump[fruits[i]]++;
            while(ump.size() > 2) {
                ump[fruits[j]]--;
                if(!ump[fruits[j]]) ump.erase(fruits[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};