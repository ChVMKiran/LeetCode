class Solution {
public:
    vector<int> rank, parent;
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return;

        if(rank[i] < rank[j]) parent[i] = j;
        else parent[j] = i;

        if(rank[i] == rank[j]) rank[i]++;
    }
    int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        ranges::sort(vec);
        for(int i = 0; i < n - 1; i++) {
            if(vec[i + 1].first - vec[i].first <= limit) {
                unite(vec[i].second, vec[i + 1].second);
            }
        }
        unordered_map<int, priority_queue<int>> ump;
        for(int i = 0; i < n; i++) find(i);
        for(int i = 0; i < n; i++) {
            ump[parent[i]].push(-nums[i]);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = -ump[parent[i]].top();
            ump[parent[i]].pop();
        }
        return ans;
    }
};