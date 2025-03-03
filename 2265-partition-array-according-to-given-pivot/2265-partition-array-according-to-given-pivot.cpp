class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size(), i = 0, ind1 = i, j = n - 1, ind2 = j;
        vector<int> res(n);
        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                res[ind1++] = nums[i];
            }
            if(nums[j] > pivot) {
                res[ind2--] = nums[j];
            }
            i++;
            j--;
        }
        while(ind1 <=  ind2) res[ind1++] = pivot;
        return res;
    }
};