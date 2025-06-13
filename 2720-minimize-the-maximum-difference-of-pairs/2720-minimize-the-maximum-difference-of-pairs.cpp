class Solution {
private:
    bool helper(vector<int>& nums, int diff, int p) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] <= diff) {
                p--;
                i++;
            }
            if(!p) break;
        }
        return p == 0;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(!p) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(helper(nums, mid, p)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
