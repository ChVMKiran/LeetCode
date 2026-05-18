class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(r == 0) return 1;
        return (int)(pow(r, 1.0 / k) + 1e-9)
            - (l == 0 ? -1 : (int)(pow(l - 1, 1.0 / k) + 1e-9));
    }
};