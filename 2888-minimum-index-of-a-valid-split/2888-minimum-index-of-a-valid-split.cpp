class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num = nums[0], count = 1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] != num) count--;
            else count++;
            if(!count) {
                num = nums[i];
                count++;
            }
        }
        count = 0;
        for(int i = 0; i < n; i++) count += (nums[i] == num);
        int freq = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == num) freq++;
            if(freq > (i + 1) / 2 && count - freq > (n - 1 - i) / 2) return i;
        }
        return -1;
    }
};