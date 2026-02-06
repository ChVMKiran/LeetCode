class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0, j = 0; i < n; i++) {
            j = max(j, i);
            while(j < n && (long long)nums[i] * k >= nums[j]) {
                j++;
            }
            maxLen = max(maxLen, j - i);
        }
        return n - maxLen;
    }
};