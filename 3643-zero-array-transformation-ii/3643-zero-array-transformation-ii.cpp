class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size(), ans = right;
        if (!isPossible(nums, queries, right)) return -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (isPossible(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size(), sum = 0;
        vector<int> vec(n + 1);
        for (int i = 0; i < k; i++) {
            int start = queries[i][0], end = queries[i][1], val = queries[i][2];
            vec[start] += val;
            vec[end + 1] -= val;
        }
        for (int i = 0; i < n; i++) {
            sum += vec[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
};