class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<int, int> ump;
        for(int e: arr1) {
            while(e) {
                ump[e]++;
                e /= 10;
            }
        }
        for(int e: arr2) {
            int len = (int)log10(e) + 1;
            while(e && len > ans) {
                if(ump.count(e)) {
                    ans = max(ans, len);
                    break;
                }
                e /= 10;
                len--;
            }
        }
        ump.clear();
        return ans;
    }
};