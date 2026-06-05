class Solution {
public:
    vector<int> segTree;
    void build(vector<int>& arr, int l, int r, int i) {
        if(l == r) {
            segTree[i] = l;
            return;
        }
        int m = l + (r - l) / 2;
        build(arr, l, m, 2 * i + 1);
        build(arr, m + 1, r, 2 * i + 2);
        if(arr[segTree[2 * i + 1]] >= arr[segTree[2 * i + 2]]) segTree[i] = segTree[2 * i + 1];
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
        int n = heights.size();
        vector<int> res;
        segTree.resize(4 * n);
        build(heights, 0, n - 1, 0);
        for(auto& q: queries) {
            if(q[0] == q[1]) {
                res.push_back(q[1]);
                continue;
            }
            else {
                auto [i, j] = minmax(q[0], q[1]);
                if(heights[i] < heights[j]) {
                    res.push_back(j);
                    continue;
                }
            }
            int l = max(q[0], q[1]) + 1, r = n - 1, ans = -1;
            while(l <= r) {
                int m = l + (r - l) / 2;
                int ind = query(heights, 0, n - 1, l, m, 0);
                if(ind == -1 || heights[ind] <= heights[q[0]] || heights[ind] <= heights[q[1]]) l = m + 1;
                else ans = ind, r = m - 1;
            }
            res.push_back(ans);
        }
        return res;
    }
};