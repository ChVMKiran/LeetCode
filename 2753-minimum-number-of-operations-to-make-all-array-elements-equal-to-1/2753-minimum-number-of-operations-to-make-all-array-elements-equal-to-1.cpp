class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ones = 0, hcf = 0; //gcd(0, N) --> N ,(N > 0)
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) ones++;
            hcf = gcd(hcf, nums[i]);
        }
        if(ones) return n - ones;
        if(hcf > 1) return -1;
        int minlen = n;
        for(int i = 0; i < n; i++) {
            hcf = 0;
            for(int j = i; j < n; j++) {
                hcf = gcd(hcf, nums[j]);
                if(hcf == 1) {
                    minlen = min(minlen, j - i + 1);
                    break;
                }
            }
        }
        return minlen + n - 2;
    }
};