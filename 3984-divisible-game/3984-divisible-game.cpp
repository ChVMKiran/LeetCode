class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n = nums.size(), diff = INT_MIN, k = 2;
        unordered_set<int> primes = {2};
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            while(num % 2 == 0) num /= 2;
            for(int j = 3; j * j <= num; j += 2) {
                if(num % j) continue;
                primes.insert(j);
                while(num % j == 0) num /= j;
            }
            if(num > 1) primes.insert(num);
        }
        int mod = 1e9 + 7;
        for(auto& p: primes) {
            int curr = 0, maxi = INT_MIN;
            for(int i = 0; i < n; i++) {
                int val = nums[i] % p ? -nums[i] : nums[i];
                curr = max(val, curr + val);
                maxi = max(maxi, curr);
            }
            if(diff < maxi) {
                diff = maxi;
                k = p;
            }
            else if(diff == maxi && k > p) {
                k = p;
            }
        }
        return ((1LL * diff * k) % mod + mod) % mod;
    }
};