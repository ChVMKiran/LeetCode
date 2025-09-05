class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans (n);
        pre[0] = 0;
        suf[n - 1] = n - 1;
        for(int i = 1; i < n; i++) { 
            if(nums[pre[i - 1]] > nums[i]) pre[i] = pre[i - 1];
            else pre[i] = i;
        }
        for(int i = n - 2; i >= 0; i--) { 
            if(nums[suf[i + 1]] < nums[i]) suf[i] = suf[i + 1];
            else suf[i] = i;
        }
        ans[n - 1] = nums[pre[n - 1]];
        for(int i = n - 2; i >= 0; i--) {
            if(nums[pre[i]] > nums[suf[i + 1]]) ans[i] = ans[i + 1]; 
            //going to largest left(ll) -> to smallest right(sr) where sr < ll -> then to largest left from sr
            //ex: 5 2 1 10 4 --> for i = 0 => [5 -> 4 -> 10]
            
            else ans[i] = nums[pre[i]]; // largest left always possible
        }
        return ans;
    }
};