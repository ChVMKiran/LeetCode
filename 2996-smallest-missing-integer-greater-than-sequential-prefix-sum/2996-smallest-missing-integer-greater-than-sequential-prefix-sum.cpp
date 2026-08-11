class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), pre = nums[0];
        bitset<51> bs;
        bool flag = true;
        bs.set(pre);
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1 && flag) pre += nums[i];
            else flag = false;
            bs.set(nums[i]);
        }
        while(pre <= 50 && bs.test(pre)) pre++;
        return pre;
    }
};