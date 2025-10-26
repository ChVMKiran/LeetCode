class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 1;
        int ind = 0, n = nums1.size();
        int mini = min(abs(nums1[0] - nums2[n]), abs(nums2[0] - nums2[n]));
        for(int i = 0; i < n; i++) {
            if(nums2[n] >= min(nums1[i], nums2[i]) && nums2[n] <= max(nums1[i], nums2[i])) {
                mini = 0;
                break;
            }
            mini = min(mini, min(abs(nums1[i] - nums2[n]), abs(nums2[i] - nums2[n])));
        }
        ans += mini;
        for(int i = 0; i < n; i++) ans += abs(nums1[i] - nums2[i]);
        return ans;
    }
};