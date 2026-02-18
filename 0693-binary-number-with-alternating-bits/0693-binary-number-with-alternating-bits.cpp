class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n & 1;
        while((n & 1) == flag) {
            n >>= 1;
            flag = !flag;
        }
        return !n;
    }
};