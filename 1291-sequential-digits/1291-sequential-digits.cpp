class Solution {
public:
    inline static int nums[45];
    bool init = []() {
        int n = 0;
        for(int i = 1; i < 10; i++) nums[n++] = i;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 10 < 9) nums[n++] = nums[i] * 10 + nums[i] % 10 + 1;
        }
        return 0;
    }();
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 0; i < 45; i++) {
            if(nums[i] >= low && nums[i] <= high) ans.push_back(nums[i]);
        }
        return ans;
    }
};