class Solution {
public:
    int n = 50000;
    vector<int> segTree;
    void update(int ind, int val, int l, int r, int i) {
        if(l == r) {
            segTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(ind <= mid) update(ind, val, l, mid, 2 * i + 1);
        else update(ind, val, mid + 1, r, 2 * i + 2);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }
    int query(int start, int end, int l, int r, int i) {
        if(start > r || l > end) return 0;
        if(start <= l && r <= end) return segTree[i];
        int mid = l + (r - l) / 2;
        int left = query(start, end, l, mid, 2 * i + 1);
        int right = query(start, end, mid + 1, r, 2 * i + 2);
        return max(left, right);
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        segTree.resize(4 * n);
        vector<bool> ans;
        set<int> st;
        st.insert(0);
        for(auto& q: queries) {
            int x = q[1];
            if(q[0] == 1) {
                auto it = st.upper_bound(x);
                int pre = *prev(it), nxt = (it != st.end()) ? *it : -1;
                update(x, x - pre, 0, n - 1, 0);
                if(nxt != -1) update(nxt, nxt - x, 0, n - 1, 0);
                st.insert(x);
            }
            else {
                auto it = st.upper_bound(x);
                int pre = *prev(it);
                int maxi = max(x - pre, query(0, pre, 0, n - 1, 0));
                ans.push_back(maxi >= q[2]);
            }
        }
        return ans;
    }
};