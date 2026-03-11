class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        // unsigned int m = n;
        // int w = bit_width(m);
        // int v = (1 << w) - 1;
        // return n ^ v;
        return n ^ ((1 << bit_width((unsigned int)n)) - 1);
    }
};