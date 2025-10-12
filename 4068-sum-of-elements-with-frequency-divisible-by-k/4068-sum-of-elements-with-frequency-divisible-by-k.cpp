class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) ump[nums[i]]++;
        for(auto [ele, freq] : ump) {
            if(freq % k == 0) ans += freq * ele;
        }
        return ans;
    }
};