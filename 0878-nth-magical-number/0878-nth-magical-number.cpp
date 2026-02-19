class Solution {
public:
    using ll = long long;
    int nthMagicalNumber(int n, int a, int b) {
        int mod = 1e9 + 7;
        ll low = min(a, b), high = n * low;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            ll cnt = mid / a + mid / b - mid / lcm(a, b);
            if(cnt >= n) high = mid - 1;
            else low = mid + 1;
        }
        return (high + 1) % mod;
    }
};