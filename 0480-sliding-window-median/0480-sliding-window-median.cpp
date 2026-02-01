class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> minis;
        priority_queue<int, vector<int>, greater<int>> maxis;
        unordered_map<int, int> lazy;
        int n = nums.size(), x = 0, y = 0;
        vector<double> ans(n - k + 1);
        for (int i = 0, j = 0; i < n; i++) {
            if(i >= k) {
                lazy[nums[i - k]]++;
                if(nums[i - k] <= minis.top()) x--;
                else y--;
            }
            if(x <= y) {
                minis.push(nums[i]);
                x++;
            }
            else{
                maxis.push(nums[i]);
                y++;
            }
            while(!minis.empty() && !maxis.empty() && minis.top() > maxis.top()) {
                int mn = minis.top(), mx = maxis.top();
                minis.pop();
                maxis.pop();
                minis.push(mx);
                maxis.push(mn);
            }
            if(x > y + 1) {
                maxis.push(minis.top());
                minis.pop();
                x--;
                y++;
            }
            if(y > x + 1) {
                minis.push(maxis.top());
                maxis.pop();
                x++;
                y--;
            }
            while(!minis.empty() && lazy.count(minis.top())) {
                if(--lazy[minis.top()] == 0) lazy.erase(minis.top());
                minis.pop();
            }
            while(!maxis.empty() && lazy.count(maxis.top())) {
                if(--lazy[maxis.top()] == 0) lazy.erase(maxis.top());
                maxis.pop();
            }
            if(i < k - 1) continue;
            if(x == y) ans[j++] = ((double)minis.top() + (double)maxis.top()) / 2.0;
            else if(x > y) ans[j++] = minis.top()*1.0;
            else ans[j++] = maxis.top()*1.0;
        }
        return ans;
    }
};