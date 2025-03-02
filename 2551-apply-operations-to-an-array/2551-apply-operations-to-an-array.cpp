class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int ind = 0, nonZeroInd = 0;
        while(ind < n){
            if(nums[ind]) {
                nums[nonZeroInd] = nums[ind];
                nonZeroInd++;
            }
            ind++;
        }
        while(nonZeroInd < n){
            nums[nonZeroInd++] = 0;
        }
        return nums;
    }
};