class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size() - 1, n = nums2.size(), i = 0, j = 0, ans = 0;
        while(--n >= 0) {
            while(m >= 0 && nums2[n] >= nums1[m]) {
                ans = max(ans, n - m);
                m--;
            }
        }
        return ans;
    }
};