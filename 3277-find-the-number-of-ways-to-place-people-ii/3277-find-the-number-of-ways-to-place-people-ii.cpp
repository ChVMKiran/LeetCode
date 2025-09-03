class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        if(v1[0] != v2[0]) return v1[0] > v2[0];
        return v1[1] < v2[1];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(),points.end(), cmp);
        for(int i = 0; i < n; i++) {
            int prev = INT_MAX;
            for(int j = i + 1; j < n; j++) {
                if(points[j][1] >= points[i][1] && prev > points[j][1]) {
                    prev = points[j][1];
                    ans++;
                    if(points[j][1] == points[i][1]) break;
                }
            }
        }
        return ans;
    }
};