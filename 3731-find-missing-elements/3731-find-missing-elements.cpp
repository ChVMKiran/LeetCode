class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> freq = 0;
        vector<int> ans;
        int n = nums.size(), mn = 100, mx = 1;
        for(int i = 0; i < n; i++) {
            freq[nums[i]] = 1;
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        for(int i = mn; i < mx; i++) {
            if(!freq[i]) ans.push_back(i);
        }
        return ans;
    }
};