class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) {
        int n = nums.size();
        int curr = 0, ans = 1, left = 0, right = 0;
        while (right < n) {
            if ((nums[right] &curr) == 0) {
                curr = curr | nums[right];
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                curr = curr ^ nums[left];
                left++;
            }
        }
        return ans;
    }
};