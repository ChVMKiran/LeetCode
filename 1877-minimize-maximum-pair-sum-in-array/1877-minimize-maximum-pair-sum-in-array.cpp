class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(), mini = nums[0], maxi = nums[0], ans = 0;
        vector<int> freq(1e5 + 1);
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        while(mini <= maxi) {
            while(mini <= maxi && freq[mini] == 0) mini++;
            while(mini <= maxi && freq[maxi] == 0) maxi--;
            if(mini > maxi) break;
            ans = max(ans, mini + maxi);
            freq[mini]--;
            freq[maxi]--;
        }
        return ans;
    }
};