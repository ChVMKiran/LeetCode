class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, h = n - 1;
        while(l <= h) {
            int m = (l + h) / 2;
            if(m > 0 && nums[m] == nums[m - 1]) {
                if((m - 1) % 2) h = m - 2;
                else l = m + 1;
            }
            else if(m < n - 1 && nums[m] == nums[m + 1]) {
                if((n - 1 - (m + 1)) % 2) l = m + 2;
                else h = m - 1;
            }
            else {
                return nums[m];
            }
        }
        return 0;
    }
};