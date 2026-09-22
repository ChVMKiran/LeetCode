class Solution {
public:
    struct Node {
        int prod, freq[5]{};
    };
    int K;
    vector<Node> segTree;
    vector<int> ans;
    void build(int st, int end, int ind, vector<int>& nums) {
        if (st == end) {
            segTree[ind].prod = nums[st] % K;
            segTree[ind].freq[nums[st] % K]++;
            return;
        }
        int mid = st + (end - st) / 2;
        build(st, mid, ind * 2 + 1, nums);
        build(mid + 1, end, ind * 2 + 2, nums);
        segTree[ind] = merge(segTree[ind * 2 + 1], segTree[ind * 2 + 2]);
    }
    Node merge(Node& left, Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        for (int i = 0; i < K; i++)
            res.freq[i] = left.freq[i];
        for (int i = 0; i < K; i++) {
            int rem = (left.prod * i) % K;
            res.freq[rem] += right.freq[i];
        }
        return res;
    }
    void update(int i, int l, int r, int ind, int val) {
        if (l == r) {
            segTree[i].freq[segTree[i].prod]--;
            segTree[i].prod = val % K;
            segTree[i].freq[val % K]++;
            return;
        }
        int m = l + (r - l) / 2;
        if (ind <= m)
            update(i * 2 + 1, l, m, ind, val);
        else
            update(i * 2 + 2, m + 1, r, ind, val);
        segTree[i] = merge(segTree[i * 2 + 1], segTree[i * 2 + 2]);
    }
    Node query(int i, int st, int end, int l, int r) {
        if (st <= l && r <= end)
            return segTree[i];
        int m = l + (r - l) / 2;
        if (end <= m)
            return query(i * 2 + 1, st, end, l, m);
        else if (m < st)
            return query(i * 2 + 2, st, end, m + 1, r);
        Node left = query(i * 2 + 1, st, end, l, m);
        Node right = query(i * 2 + 2, st, end, m + 1, r);
        return merge(left, right);
    }
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        K = k;
        segTree.resize(4 * n);
        build(0, n - 1, 0, nums);
        ans.resize(queries.size());
        for (int i = 0; i < m; i++) {
            auto& q = queries[i];
            int ind = q[0], val = q[1], st = q[2], x = q[3];
            update(0, 0, n - 1, ind, val);
            ans[i] = query(0, st, n - 1, 0, n - 1).freq[x];
        }
        return ans;
    }
};