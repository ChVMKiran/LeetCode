class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMin = 0, currMax = 0, totalMin = 0, totalMax = 0;
        for(int &i: nums){
            currMin = min(i, currMin+i);
            totalMin = min(currMin, totalMin);
            currMax = max(i, currMax+i);
            totalMax = max(currMax, totalMax);
        }
        return max(totalMax, -totalMin);
    }
};