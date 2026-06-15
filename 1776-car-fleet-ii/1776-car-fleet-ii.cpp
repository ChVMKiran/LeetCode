class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<int> st;
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            int p = cars[i][0], s = cars[i][1];
            while(!st.empty()) {
                int j = st.top();
                int dist = cars[j][0] - p, rel = s - cars[j][1];
                double val = (1.0 * dist) / rel;
                if(rel <= 0 || (val >= ans[j] && ans[j] != -1)) st.pop();
                else break;
            }
            if(!st.empty()) ans[i] = (cars[st.top()][0] - p) / (1.0 * s - cars[st.top()][1]);
            st.push(i);
        }
        return ans;
    }
};