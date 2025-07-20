class Solution {
public:
    void sieve(vector<bool> &isPrime, int n) {
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(!isPrime[i]) continue;
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    long long splitArray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        if(!n) return nums[0];
        vector<bool> isPrime(n, true);
        sieve(isPrime, n);
        for(int i = 0; i < n; i++) {
            if(isPrime[i]) ans += nums[i];
            else ans -= nums[i];
        }
        return abs(ans);
    }
};