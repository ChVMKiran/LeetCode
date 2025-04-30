class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(const int &num : nums) {
            count += (int(log10(num)) % 2 == 1);
        }
        return count;
    }
};