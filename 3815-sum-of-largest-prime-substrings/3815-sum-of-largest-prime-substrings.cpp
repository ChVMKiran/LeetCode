class Solution {
public:
    bool isPrime(long long n) {
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;
        for(long long i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long ans = 0;
        set<long long>st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                long long val = stoll(s.substr(i, j - i + 1));
                if(isPrime(val)) st.insert(val);
            }
        }
        vector<long long> vec;
        auto rit = st.rbegin();
        int j = 0;
        while(j<3 && rit!=st.rend()) {
            ans += *rit;
            j++;
            rit++;
        }
        return ans;
    }
};