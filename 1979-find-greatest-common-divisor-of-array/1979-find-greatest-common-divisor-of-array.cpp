class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = 1000, mx = 1;
        for(auto& n: nums) mn = min(mn, n), mx = max(mx, n);
        return __gcd(mn, mx);
    }
};