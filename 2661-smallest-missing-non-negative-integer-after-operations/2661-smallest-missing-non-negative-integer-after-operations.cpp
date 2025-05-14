class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value);
        for(int &i :nums) {
            freq[((i % value) + value) % value]++;
        }
        int ans = 0;
        while(true) {
            if(!freq[ans % value]) return ans;
            freq[ans++ % value]--;
        }
        return -1;
    }
};