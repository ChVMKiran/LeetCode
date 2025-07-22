class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> ust;
        int n = nums.size(), ans = 0, curr = 0;
        for(int i = 0, j = 0; i < n; i++) {
            curr += nums[i];
            if(ust.count(nums[i])) {
                while(j < n && nums[i] != nums[j]) {
                    ust.erase(nums[j]);
                    curr -= nums[j];
                    j++;
                }
                curr -= nums[j++];
            }
            ust.insert(nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};