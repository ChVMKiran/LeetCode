class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool flag = true;
            int pre = -1, mini = INT_MAX, ind1 = -1, ind2 = -1;
            for(int j = 0; j < n; j++) {
                if(nums[j] == 1001) continue;
                if(pre != -1) {
                    if(nums[pre] > nums[j]) flag = false;
                    if(mini > nums[pre] + nums[j]) {
                        ind1 = pre;
                        ind2 = j;
                        mini = nums[pre] + nums[j];
                    }
                }
                pre = j;
            }
            if(flag) return i;
            nums[ind1] = mini;
            nums[ind2] = 1001;
        }
        return n - 1;
    }
};