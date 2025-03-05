class Solution {
public:
    long long coloredCells(int n) {
        long long highestOdd = 2*n -1, evens = highestOdd/2;
        long long upperHalf = highestOdd*(highestOdd + 1)/2 - evens*(evens + 1);
        return (upperHalf<<1) - highestOdd;
    }
};