class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        priority_queue<pair<int, int>> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        unordered_map<int,int> state;
        long long curr = 0, ans = LLONG_MAX;
        int n = nums.size(), x = 0, y = 0;
        for (int i = 1; i <= dist + 1; i++) {
            maxheap.push({nums[i], i});
            state[i] = 0;
            curr += nums[i];
            x++;
            if (maxheap.size() == k) {
                auto t = maxheap.top(); maxheap.pop();
                state[t.second] = 1;
                curr -= t.first;
                minheap.push(t);
                x--; y++;
            }
            if (maxheap.size() == k - 1)
                ans = min(ans, curr);
        }
        for (int i = dist + 2, j = 1; i < n; i++, j++) {
            if (state[j] == 0) {
                curr -= nums[j];
                x--;
            } else {
                y--;
            }
            state[j] = -1;
            if (x < k - 1) {
                maxheap.push({nums[i], i});
                state[i] = 0;
                curr += nums[i];
                x++;
            } else {
                minheap.push({nums[i], i});
                state[i] = 1;
                y++;
            }
            while (!maxheap.empty() && state[maxheap.top().second] == -1)
                maxheap.pop();
            while (!minheap.empty() && state[minheap.top().second] == -1)
                minheap.pop();
            while (maxheap.size() < k - 1) {
                auto t = minheap.top(); minheap.pop();
                state[t.second] = 0;
                curr += t.first;
                maxheap.push(t);
            }
            while (!maxheap.empty() && !minheap.empty() &&
                   maxheap.top().first > minheap.top().first) {
                auto a = maxheap.top(); maxheap.pop();
                auto b = minheap.top(); minheap.pop();
                curr -= a.first;
                curr += b.first;
                state[a.second] = 1;
                state[b.second] = 0;
                maxheap.push(b);
                minheap.push(a);
            }
            ans = min(ans, curr);
        }
        return ans + nums[0];
    }
};
