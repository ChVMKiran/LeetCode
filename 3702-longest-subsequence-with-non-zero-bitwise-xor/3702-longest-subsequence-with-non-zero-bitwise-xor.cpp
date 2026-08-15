class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        bool flag = 0;
        for(auto& e: nums) {
            if(e) flag = 1;
            res ^= e;
        }
        if(res) return nums.size();
        if(flag) return nums.size() - 1;
        return 0;
    }
};