class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size(), lastMax = INT_MIN, ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] - k > lastMax) {
                ans++;
                lastMax = nums[i] - k;
            }
            else if(nums[i] + k > lastMax){
                ans++;
                lastMax++;
            }
        }
        return ans;
    }
};