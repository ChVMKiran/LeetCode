class Solution {
public:
    vector<int> segTree;
    void build(vector<int>& heights, int l, int r, int i) {
        if(l == r) {
            segTree[i] = l;
            return;
        }
        int m = l + (r - l) / 2;
        build(heights, l, m, 2 * i + 1);
        build(heights, m + 1, r, 2 * i + 2);
        if(heights[segTree[2 * i + 1]] >= heights[segTree[2 * i + 2]]) segTree[i] = segTree[2 * i + 1];
        else segTree[i] = segTree[2 * i + 2];
    }
    int query(vector<int>& heights, int start, int end, int l, int r, int i) {
        if(r < start || l > end) return -1;
        if(l <= start && end <= r) return segTree[i];
        int m = start + (end - start) / 2;
        int left = query(heights, start, m, l, r, 2 * i + 1);
        int right = query(heights, m + 1, end, l, r, 2 * i + 2);
        if(left == -1) return right;
        if(right == -1) return left;
        if(heights[left] >= heights[right]) return left;
        return right;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> res(m);
        segTree.resize(4 * n);
        build(heights, 0, n - 1, 0);
        for(int i = 0; i < m; i++) {
            auto &q = queries[i];
            if(q[0] == q[1]) {
                res[i] = q[1];
                continue;
            }
            else {
                auto [j, k] = minmax(q[0], q[1]);
                if(heights[j] < heights[k]) {
                    res[i] = k;
                    continue;
                }
            }
            int l = max(q[0], q[1]) + 1, r = n - 1, ans = -1;
            while(l <= r) {
                int m = l + (r - l) / 2;
                int ind = query(heights, 0, n - 1, l, m, 0);
                if(heights[ind] <= heights[q[0]] || heights[ind] <= heights[q[1]]) l = m + 1;
                else ans = ind, r = m - 1;
            }
            res[i] = ans;
        }
        return res;
    }
};