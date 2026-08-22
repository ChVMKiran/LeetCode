class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1, val = n;
        while(n) {
            int rem = n % 10;
            sum += rem;
            prod *= rem;
            n /= 10;
        }
        return val % (sum + prod) == 0;
    }
};