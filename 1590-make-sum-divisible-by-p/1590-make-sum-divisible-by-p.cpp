class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int req = 0, n = nums.size();
        for(int i = 0; i < n; i++) req = (req + nums[i])  % p;
        int curr = 0, ans = n;
        unordered_map<int, int> ump;
        ump[0] = -1;
        for(int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            ump[curr % p] = i;
            if(ump.count((curr - req + p) % p)) ans = min(ans, i - ump[(curr - req + p) % p]);
        }
        return ans == n ? -1 : ans;
    }
};