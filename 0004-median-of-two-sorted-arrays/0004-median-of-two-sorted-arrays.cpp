class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), l = 0, h = n1;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        while(l <= h) {
            int m1 = (l + h) >> 1, m2 = ((n1 + n2 + 1) >> 1) - m1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(m1 > 0) l1 = nums1[m1 - 1];
            if(m2 > 0) l2 = nums2[m2 - 1];
            if(m1 < n1) r1 = nums1[m1];
            if(m2 < n2) r2 = nums2[m2];
            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) h = m1 - 1;
            else l = m1 + 1;
        }
        return 0;
    }
};