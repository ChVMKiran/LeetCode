class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend) return 0;
        int pos = -1;
        if(dividend < 0 == divisor < 0) pos = 1;
        long a = abs(static_cast<long> (dividend));
        long b = abs(static_cast<long> (divisor));
        long ans = 0;
        while(a >= b) {
            int p = 0;
            while(a >= (b << p)) p++;
            p--;
            ans += (1 << p);
            a -= (b << p);
        }
        if(ans * pos == INT_MIN) return INT_MAX;
        return ans * pos;
    }
};