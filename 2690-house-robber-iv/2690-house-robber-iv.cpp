class Solution {
private:
    int n;
    bool isPossible(vector<int>& nums, int reward, int k) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= reward) {
                count++;
                i++;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        n = nums.size();
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(nums, mid, k)) high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;
    }
};