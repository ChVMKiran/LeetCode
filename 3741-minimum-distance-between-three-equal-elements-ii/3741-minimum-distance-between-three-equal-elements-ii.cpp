class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        unordered_map<int, pair<int, int>> ump;
        for(int k = 0; k < n; k++) {
            if(!ump.count(nums[k])) {
                ump[nums[k]] = {k, k};
            }
            else {
                auto& [i, j] = ump[nums[k]];
                if(i == j) {
                    j = k;
                }
                else {
                    int val = abs(i - j) + abs(j - k) + abs(k - i);
                    if(ans == -1 || ans > val) 
                        ans = val;
                    i = j;
                    j = k;
                }
            }
        }
        return ans;
    }
};