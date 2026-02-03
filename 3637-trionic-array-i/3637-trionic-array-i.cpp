class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p = false;
        int n = nums.size(), i = 1, j = 1;
        while(i < n && nums[i] > nums[i - 1]) i++;
        if(i == j || i == n) return false;
        j = i;
        while(i < n && nums[i] < nums[i - 1]) i++;
        if(i == j || i == n) return false;
        j = i;
        while(i < n && nums[i] > nums[i - 1]) i++;
        return i == n;
    }
};