class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size(), left = 1, right = n - 2;
        long long leftSum = 0, rightSum = 0;
        while(left < n && nums[left] > nums[left - 1]) {
            leftSum += nums[left - 1];
            left++;
        }
        left--;
        while(right >= 0 && nums[right] > nums[right + 1]) {
            rightSum += nums[right + 1];
            right--;
        }
        right++;
        if(right - left > 1) return -1;
        long long ans = abs(leftSum - rightSum);
        if(right != left) return ans;
        ans = abs(leftSum + nums[left] - rightSum);
        ans = min(ans, abs(leftSum - nums[left] - rightSum));
        return ans;
    }
};