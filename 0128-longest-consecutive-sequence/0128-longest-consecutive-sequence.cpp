class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust;
        int n = nums.size();
        if(!n) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ust.insert(nums[i]);
        }
        for(int num : ust) {
            if(ust.find(num - 1) == ust.end()) {
                int len = 1;
                while(ust.find(num + len) != ust.end()) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};