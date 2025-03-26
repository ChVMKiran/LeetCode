class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res(n - k + 1);
        for(int i = 0; i < n; i++) {
            if(i - dq.front() == k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res[i - k + 1] = nums[dq.front()];
        }
        return res;
    }
};