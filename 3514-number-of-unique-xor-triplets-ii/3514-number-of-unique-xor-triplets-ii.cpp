class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(int i = 0; i < n; i++) mx = max(mx, nums[i]);
        int m = 1 << bit_width(static_cast<unsigned>(mx));
        vector<int> one(m), two(m), three(m);
        for(int i = 0; i < n; i++) {
            one[nums[i]] = 1;
            for(int j = 0; j < m; j++) {
                if(one[j]) two[j ^ nums[i]] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(two[j]) three[j ^ nums[i]] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(three[i]) ans++;
        }
        return ans;
    }
};