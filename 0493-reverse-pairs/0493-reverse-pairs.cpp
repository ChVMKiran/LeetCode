class Solution {
public:
    int countPairs(vector<int>& nums, int l, int m, int h) {
        int res = 0;
        for(int i = l, j = m + 1; i <= m; i++) {
            while(j <= h && nums[i] > 2LL * nums[j]) j++;
            res += (j - m - 1);
        }
        return res;
    }
    void merge(vector<int>& nums, int l, int m, int h) {
        vector<int> temp(h - l + 1);
        int ind = 0, i = l, j = m + 1;
        while(i <= m && j <= h) {
            if(nums[i] < nums[j]) {
                temp[ind++] = nums[i++];
            }
            else {
                temp[ind++] = nums[j++];
            }
        }
        while(i <= m) temp[ind++] = nums[i++];
        while(j <= h) temp[ind++] = nums[j++];
        for(int i = 0; i <= h - l; i++) {
            nums[i + l] = temp[i];
        }
    }
    int mergeSort(vector<int>& nums, int l, int h) {
        if(l >= h) return 0;
        int m = l + (h - l) / 2, cnt = 0;
        cnt += mergeSort(nums, l, m);
        cnt += mergeSort(nums, m + 1, h);
        cnt += countPairs(nums, l, m, h);
        merge(nums, l, m, h);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};