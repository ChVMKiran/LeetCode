class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, val = 0;
        for(int &e: gain) {
            val += e;
            maxi = max(maxi, val);
        }
        return maxi;
    }
};