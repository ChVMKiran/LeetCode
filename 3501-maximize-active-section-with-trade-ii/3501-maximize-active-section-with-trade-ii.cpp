class Solution {
public:
    vector<int> segTree, pairSum;
    void build(int ind, int l, int r) {
        if(l == r) {
            segTree[ind] = pairSum[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(ind * 2 + 1, l, m);
        build(ind * 2 + 2, m + 1, r);
        segTree[ind] = max(segTree[ind * 2 + 1], segTree[ind * 2 + 2]);
    }
    int query(int st, int e, int l, int r, int ind) {
        if(l > e || r < st) return INT_MIN;
        if(l >= st && r <= e) return segTree[ind];
        int m = l + (r - l) / 2;
        return max(query(st, e, l, m, ind * 2 + 1), query(st, e, m + 1, r, ind * 2 + 2));
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int i = 0, cnt = 0, n = s.size();
        vector<int> blockSt, blockEnd;
        while(i < n) {
            if(s[i] == '0') {
                int st = i;
                while(i < n && s[i] == '0') i++;
                blockSt.push_back(st);
                blockEnd.push_back(i - 1);
            }
            else cnt++, i++;
        }
        int m = queries.size();
        vector<int> ans(m, cnt);
        int sz = blockSt.size();
        if(sz < 2) return ans;
        pairSum.resize(sz - 1);
        segTree.resize(4 * (sz - 1));
        for(int i = 0; i < sz - 1; i++) 
            pairSum[i] = (blockEnd[i + 1] - blockSt[i + 1] + 1) + (blockEnd[i] - blockSt[i] + 1);
        build(0, 0, sz - 2);
        for(int i = 0; i < m; i++) {
            auto& l = queries[i][0], h = queries[i][1];
            int low = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd);
            int high = upper_bound(begin(blockSt), end(blockSt), h) - begin(blockSt) - 1;
            if(low < high) {
                int firstLen = blockEnd[low] - max(blockSt[low], l) + 1;
                int lastLen = min(blockEnd[high], h) - blockSt[high] + 1;
                if(high - low == 1) {
                    ans[i] += firstLen + lastLen;
                }
                else {
                    int best = firstLen + blockEnd[low + 1] - blockSt[low + 1] + 1;
                    best = max(best, lastLen + blockEnd[high - 1] - blockSt[high - 1] + 1);
                    best = max(best, query(low + 1, high - 2, 0, sz - 2, 0));
                    ans[i] += best;
                }
            }
        }
        return ans;
    }
};