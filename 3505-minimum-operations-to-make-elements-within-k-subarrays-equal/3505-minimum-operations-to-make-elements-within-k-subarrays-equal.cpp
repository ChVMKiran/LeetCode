class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        const long long INF = 1e16;
        int n = nums.size();
        long long dp[100001][16], cost[100001];

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

        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                dp[i][j] = INF;
            }
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                long long skip = dp[i - 1][j], take = INF;
                if(i >= x) {
                    take = cost[i - x] + dp[i - x][j - 1];
                }
                dp[i][j] = min(skip, take);
            }
        }

        return dp[n][k];
    }
};