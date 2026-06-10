class Solution {
public:
    vector<pair<int, int>> segTree;
    void build(int l, int r, vector<int>& nums, int i) {
        if(l == r) {
            segTree[i] = {nums[l], nums[l]};
            return;
        }
        int m = l + (r - l) / 2;
        build(l, m, nums, 2 * i + 1);
        build(m + 1, r, nums, 2 * i + 2);
        segTree[i] = {min(segTree[2 * i + 1].first, segTree[2 * i + 2].first),
                      max(segTree[2 * i + 1].second, segTree[2 * i + 2].second)};
    }
    pair<int, int> query(int l, int r, int ql, int qr, int i) {
        if(r < ql || l > qr) return {INT_MAX, INT_MIN};
        if(ql <= l && r <= qr) return segTree[i];
        int m = l + (r - l) / 2;
        auto left = query(l, m, ql, qr, 2 * i + 1);
        auto right = query(m + 1, r, ql, qr, 2 * i + 2);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        segTree.resize(4 * n);
        long long ans = 0;
        build(0, n - 1, nums, 0);
        priority_queue<tuple<int, int, int>> pq;
        for(int i = 0; i < n; i++) {
            auto [mini, maxi] = query(0, n - 1, i, n - 1, 0);
            pq.push({maxi - mini, i, n - 1});
        }
        while(k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if(l < r) {
                auto [mini, maxi] = query(0, n - 1, l, r - 1, 0);
                pq.push({maxi - mini, l, r - 1});
            }
        }
        return ans;
    }
};