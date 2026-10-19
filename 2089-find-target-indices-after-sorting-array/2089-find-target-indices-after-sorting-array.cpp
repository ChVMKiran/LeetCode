class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0, freq = 0;
        for(int& n: nums) {
            if(n < target) cnt++;
            else if(n == target) freq++;
        }
        vector<int> res(freq);
        iota(res.begin(), res.end(), cnt);
        return res;
    }
};