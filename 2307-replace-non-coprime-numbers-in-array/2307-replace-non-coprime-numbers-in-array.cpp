class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int val = nums[i];
            while(!ans.empty()) {
                int hcf = gcd(val, ans.back());
                if(hcf == 1) break;
                val = val / hcf * ans.back();
                ans.pop_back();
            }
            ans.push_back(val);
        }
        return ans;
    }
};