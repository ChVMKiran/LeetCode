class Solution {
public:
    long long dp[100001][16], cost[100001];
    int n, x;
    long long helper(int i, int c) {
        if(c == 0) return 0;
        if(i >= n) return 1e16;

        if(dp[i][c] != -1) return dp[i][c];

        int last = i + c * x - 1;
        if(last >= n) return dp[i][c] = 1e16;

        long long take = cost[i] + helper(i + x, c - 1);
        long long skip = helper(i + 1, c);

        return dp[i][c] = min(take, skip);
    }
    long long minOperations(vector<int>& nums, int X, int k) {
        memset(dp, -1, sizeof(dp));
        n = nums.size(), x = X;

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;
        for(int i = 0; i < n; i++) {
            if(i >= x) {
                if(left.find(nums[i - x]) != left.end()) {
                    left.erase(left.find(nums[i - x]));
                    leftSum -= nums[i - x];
                } 
                else {
                    right.erase(right.find(nums[i - x]));
                    rightSum -= nums[i - x];
                }
            }

            if(left.size() <= right.size()) {
                left.insert(nums[i]);
                leftSum += nums[i];
            }
            else {
                right.insert(nums[i]);
                rightSum += nums[i];
            }

            if(!left.empty() && !right.empty()) {
                long long leftMax = *left.rbegin(), rightMin = *right.begin();
                if(leftMax > rightMin) {
                    left.erase(prev(left.end()));
                    right.erase(right.begin());
                    left.insert(rightMin);
                    right.insert(leftMax);
                    leftSum += rightMin - leftMax;
                    rightSum += leftMax - rightMin;
                }
            }
            
            if(i >= x - 1) {
                int median = *left.rbegin();
                cost[i - x + 1] = (median * left.size() - leftSum) + (rightSum - median * right.size());
            }
        }
        return helper(0, k);
    }
};