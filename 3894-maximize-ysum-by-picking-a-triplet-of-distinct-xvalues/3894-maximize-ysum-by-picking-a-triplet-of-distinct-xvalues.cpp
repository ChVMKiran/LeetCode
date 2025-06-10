class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> ump;
        int n = x.size();
        for(int i = 0; i < n; i++) {
            if(ump.find(x[i]) != ump.end()) ump[x[i]] = max(ump[x[i]], y[i]);
            else ump[x[i]] = y[i];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &[ele, val] :ump) {
            if(pq.size() == 3 && pq.top() < val) {
                pq.pop();
            }
            if(pq.size() < 3) pq.push(val);
        }
        if(pq.size() < 3) return -1;
        int ans = pq.top();
        pq.pop();
        ans += pq.top();
        pq.pop();
        ans += pq.top();
        return ans;
    }
};