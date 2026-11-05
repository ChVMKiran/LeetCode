class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        set<int> st(arr2.begin(), arr2.end());
        int ans = 0;
        for(int& n: arr1) {
            auto it = st.lower_bound(n - d);
            if(it == st.end() || *it > n + d) {
                ans++;
            }
        }
        return ans;
    }
};