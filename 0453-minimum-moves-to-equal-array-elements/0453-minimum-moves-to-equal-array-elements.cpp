class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end()), total = 0;
        for(const int& i: nums) {
            total += (i - mini);
        }
        return total;
    }
};