class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), i = 0, j = n - 1, leftMax = height[i], rightMax = height[j], ans = 0;
        while(i <= j) {
            if(leftMax < rightMax) {
                leftMax = max(leftMax, height[i]);
                ans += max(0, leftMax - height[i]);
                i++;
            }
            else {
                rightMax = max(rightMax, height[j]);
                ans += max(0, rightMax - height[j]);
                j--;
            }
        }
        return ans;
    }
};