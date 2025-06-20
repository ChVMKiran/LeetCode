class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, cnt = 0;
        unordered_map<int, int> ump;
        while(right < n) {
            if(!ump.count(nums[right]) || !ump[nums[right]]) k--;
            ump[nums[right]]++;
            while(k < 0) {
                ump[nums[left]]--;
                if(!ump[nums[left]]) k++;
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
};