class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> freq(maxi + 2);
        for(int i = 0; i < n; i++) {
            freq[max(0, nums[i] - k)]++;
            freq[min(maxi + 1, nums[i] + k + 1)]--;
        }
        int ans = freq[0];
        for(int i = 1; i < maxi + 2; i++) {
            freq[i] += freq[i - 1];
            ans = max(ans, freq[i]);
        }
        return ans;
    }
};