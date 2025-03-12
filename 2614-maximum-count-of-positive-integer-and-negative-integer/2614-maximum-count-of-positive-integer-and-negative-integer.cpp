class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0;
        int l = 0, h = n - 1;
        while(l <= h) {
            int mid = (l + h)>>1;
            if(nums[mid] <= 0) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        pos = n - h - 1;
        l = 0, h = n - 1;
        while(l <= h) {
            int mid = (l + h)>>1;
            if(nums[mid] < 0) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        neg = h + 1;
        return max(pos, neg);
    }
};