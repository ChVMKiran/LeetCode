class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) ump[nums1[i]]++;
        for(int i = 0; i < n; i++) ump[nums2[i]]--;
        for(auto &[k, v]: ump) {
            if(!v) continue;
            if(v % 2) return -1;
            if(v > 0) ans += v / 2;
        }
        return ans;
    }
};