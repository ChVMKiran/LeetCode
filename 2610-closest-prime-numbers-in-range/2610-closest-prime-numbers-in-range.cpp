class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        vector<bool> sieve(right + 1, true);
        for(int i = 2; i * i <= right; i++) {
            if(sieve[i]) {
                for(int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }
        for(int i = max(2, left); i <= right; i++) {
            if(sieve[i]) primes.push_back(i);
        }
        vector<int> ans(2, -1);
        for(int i = primes.size() - 1; i > 0; i--) {
            if(ans[0] == -1) {
                ans[0] = primes[i - 1];
                ans[1] = primes[i];
            }
            else if(ans[1] - ans[0] >= primes[i] - primes[i - 1]) {
                ans[0] = primes[i - 1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
};