class Solution {
public:
    struct Node {
        int lf, rf, maxi;
        char left, right;
    };
    string s;
    vector<Node> segTree;
    void build(int l, int r, int ind) {
        if(l == r) {
            segTree[ind] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int m = l + (r - l) / 2;
        build(l, m, ind * 2 + 1);
        build(m + 1, r, ind * 2 + 2);
        int lcf = segTree[ind * 2 + 1].lf, rcf = segTree[ind * 2 + 2].rf;
        int lc = segTree[ind * 2 + 1].rf, rc = segTree[ind * 2 + 2].lf;
        int mx = max(segTree[ind * 2 + 1].maxi, segTree[ind * 2 + 2].maxi);
        if(s[m] == s[m + 1]) {
            mx = max(mx, lc + rc);
            if(segTree[ind * 2 + 1].lf == m - l + 1) lcf += rc;
            if(segTree[ind * 2 + 2].rf == r - m) rcf += lc;
        }
        segTree[ind] = {lcf, rcf, mx, s[l], s[r]};
    }
    void update(int st, int end, int ind, int pos, char c) {
        if(st == end) {
            segTree[ind] = {1, 1, 1, c, c};
            return;
        }
        int mid = st + (end - st) / 2;
        if(pos <= mid) update(st, mid, ind * 2 + 1, pos, c);
        else update(mid + 1, end, ind * 2 + 2, pos, c);
        int lcf = segTree[ind * 2 + 1].lf, rcf = segTree[ind * 2 + 2].rf;
        int lc = segTree[ind * 2 + 1].rf, rc = segTree[ind * 2 + 2].lf;
        int mx = max(segTree[ind * 2 + 1].maxi, segTree[ind * 2 + 2].maxi);
        if(segTree[ind * 2 + 1].right == segTree[ind * 2 + 2].left) {
            mx = max(mx, lc + rc);
            if(segTree[ind * 2 + 1].lf == mid - st + 1) lcf += rc;
            if(segTree[ind * 2 + 2].rf == end - mid) rcf += lc;
        }
        char left = segTree[ind * 2 + 1].left, right = segTree[ind * 2 + 2].right;
        segTree[ind] = {lcf, rcf, mx, left, right};
    }
    vector<int> longestRepeating(string str, string queryCharacters, vector<int>& queryIndices) {
        s = str;
        int n = s.size();
        segTree.resize(4 * n);
        build(0, n - 1, 0);
        int m = queryCharacters.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            update(0, n - 1, 0, queryIndices[i], queryCharacters[i]);
            ans[i] = segTree[0].maxi;
        }
        return ans;
    }
};