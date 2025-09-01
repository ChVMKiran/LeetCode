class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n; i++) {
            double gain = double(classes[i][0] + 1) / (classes[i][1] + 1) - double(classes[i][0]) / classes[i][1];
            pq.push({gain, i});
        }
        while(extraStudents--) {
            auto [gain, ind] = pq.top();
            pq.pop();
            classes[ind][0]++;
            classes[ind][1]++;
            gain = double(classes[ind][0] + 1) / (classes[ind][1] + 1) - double(classes[ind][0]) / classes[ind][1];
            pq.push({gain, ind});
        }
        for(int i = 0; i < n; i++) {
            ans += double(classes[i][0]) / classes[i][1];
        }
        return ans / n;
    }
};