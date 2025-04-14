class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> ust;
        for(int i = 0; i < n; i++) {
            if(k > nums[i]) return -1;
            else if(k < nums[i]) ust.insert(nums[i]);
        }
        return ust.size();
    }
};