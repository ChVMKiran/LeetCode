class Solution {
public:
    long long removeZeros(long long n) {
        long long num = 0;
        while(n) {
            if(n % 10)
                num = num * 10 + n % 10;
            n /= 10;
        }
        long long ans = 0;
        while(num) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
};