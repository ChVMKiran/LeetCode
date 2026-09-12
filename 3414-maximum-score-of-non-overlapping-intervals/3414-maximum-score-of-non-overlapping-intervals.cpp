class Solution {
public:
    struct Node {
        long long weight = -1;
        vector<int> idxs;
    };
    vector<vector<Node>> dp;
    int search(vector<vector<int>>& vec, int r) {
        int lo = 0, hi = vec.size() - 1;
        int result = hi + 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }
    Node helper(int cnt, vector<vector<int>>& vec, int i) {
        if(i == vec.size() || cnt == 4) return {0, {}};
        if(dp[i][cnt].weight != -1) return dp[i][cnt];
        Node skip = helper(cnt, vec, i + 1);
        int next_ind = search(vec, vec[i][1]);
        Node next_res = helper(cnt + 1, vec, next_ind);
        Node take;
        take.weight = vec[i][2] + next_res.weight;
        take.idxs = next_res.idxs;
        take.idxs.push_back(vec[i][3]);
        sort(take.idxs.begin(), take.idxs.end());
        Node best = skip;
        if (take.weight > best.weight || 
           (take.weight == best.weight && take.idxs < best.idxs)) {
            best = take;
        }
        return dp[i][cnt] = best;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector vec(n, vector<int>(4));
        for (int i = 0; i < n; i++)
            vec[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        sort(vec.begin(), vec.end());
        dp.assign(n, vector<Node>(4));
        return helper(0, vec, 0).idxs;
    }
};