class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int &i: nums) {
            if(empty(lis) || lis.back() < i) lis.push_back(i);
            else {
                *lower_bound(begin(lis), end(lis), i) = i;
            }
        }
        return size(lis);
    }
};