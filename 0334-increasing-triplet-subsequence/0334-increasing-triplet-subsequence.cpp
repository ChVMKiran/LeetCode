class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(res.empty() || res.back() < nums[i]) {
                if(res.size() == 2) return true;
                res.push_back(nums[i]);
            }
            else {
                if(res.size() == 1 || res[0] >= nums[i]) res[0] = nums[i];
                else if(res[1] > nums[i]) res[1] = nums[i];
            }
        }
        return false;
    }
};