class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size(), count = 0;
        map<pair<int, int>, int> ump;
        for(int i = 0; i < n; i++) {
            if(dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            count += ump[{dominoes[i][0], dominoes[i][1]}]++;
        }
        return count;
    }
};