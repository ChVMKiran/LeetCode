class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> invert(n + 1);
        for(int i = 0; i < n; i++) {
            if(i) {
                invert[i] ^= invert[i - 1];
            }
            nums[i] ^= invert[i];
            if(!nums[i]) {
                if(i > n - k) return -1;
                invert[i] ^= 1;
                invert[i + k] ^= 1;
                ans++;
            }
        }
        return ans;
    }
};
