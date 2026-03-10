class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, j = 0, k = 0, p = 1, n = nums.size();
        vector<int> res(n);
        for (i = 0; i < n; i++) {
            if (nums[i] != 0)
                p *= nums[i];
            else
                k++;
        }
        if (k == n)
            p = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] != 0 && k > 0) {
                res[j++] = 0;
            } else if (nums[i] == 0 && k > 1) {
                res[j++] = 0;
            } else if (nums[i] == 0) {
                res[j++] = p;
            } else {
                res[j++] = p / nums[i];
            }
        }
        return res;
    }
};