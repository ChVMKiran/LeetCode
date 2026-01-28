class Solution {
public:
    double fun(double x, long n) {
        double ans = 1;
        while(n) {
            if(n % 2) {
                ans *= x;
                n--;
            }
            else {
                x *= x;
                n /= 2;
            }
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n < 0) return 1.0 / fun(x, -(long)n);
        return fun(x, n);
    }
};