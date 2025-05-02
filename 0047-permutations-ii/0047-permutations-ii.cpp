class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int>ump;
        for(int &i : nums) ump[i]++;
        rec(ans, curr, nums.size(), ump);
        return ans;
    }
    void rec(vector<vector<int>>& ans, vector<int>& curr, int n, unordered_map<int, int>& ump) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for(auto &fre : ump) {
            if(fre.second) {
                ump[fre.first]--;
                curr.push_back(fre.first);
                rec(ans, curr, n, ump);
                ump[fre.first]++;
                curr.pop_back();
            }
        }
    }
};