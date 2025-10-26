class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            pq.push(nums[i] * nums[i]);
        }
        int k = n / 2 + n % 2;
        long long ans = 0;
        while(k--) {
            ans += (long long)pq.top();
            pq.pop();
        }
        while(!pq.empty()) {
            ans -= (long long)pq.top();
            pq.pop();
        }
        return ans;
    }
};