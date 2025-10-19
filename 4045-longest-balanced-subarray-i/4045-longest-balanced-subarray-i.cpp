class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int j = 0; j < n; j++) {
            unordered_set<int> evens, odds;
            for(int i = j; i < n; i++) {
                if(nums[i] % 2 == 0) evens.insert(nums[i]);
                else odds.insert(nums[i]);
                if(evens.size() == odds.size()) ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};