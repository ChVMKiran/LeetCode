class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 0) {
                digitSum[i] += x % 10;
                x /= 10;
            }
        }
        vector<int> inds(n);
        iota(inds.begin(), inds.end(), 0);
        sort(inds.begin(), inds.end(), [&](int a, int b) {
            if (digitSum[a] != digitSum[b]) {
                return digitSum[a] < digitSum[b];
            }
            return nums[a] < nums[b];
        });
        vector<int> targetPos(n);
        for (int i = 0; i < n; i++) {
            targetPos[inds[i]] = i;
        }
        vector<int> vis(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                int j = i;
                while (!vis[j]) {
                    vis[j] = true;
                    j = targetPos[j];
                }
            }
        }
        return n - cnt;
    }
};