class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> ump;
        int ans = 0;
        for(const int &num : answers) {
            ump[num]++;
        }
        for(const auto &freq : ump) {
            if(freq.first == freq.second - 1) ans += freq.first + 1;
            else ans += ceil(freq.second / (1.0 * (freq.first + 1))) * (freq.first + 1);
        }
        return ans;
    }
};