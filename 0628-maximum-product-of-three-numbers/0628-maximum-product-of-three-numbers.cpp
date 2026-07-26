class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), a = -1001, b = a, c = a;
        int x = 1001, y = x;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= a) {
                c = b;
                b = a;
                a = nums[i];
            }
            else if(nums[i] >= b) {
                c = b;
                b = nums[i];
            }
            else if(nums[i] > c) {
                c = nums[i];
            }

            if(nums[i] < x) {
                y = x;
                x = nums[i];
            }
            else if(nums[i] < y) {
                y = nums[i];
            }
        }
        return max(a * b * c, x * y * a);
    }
};