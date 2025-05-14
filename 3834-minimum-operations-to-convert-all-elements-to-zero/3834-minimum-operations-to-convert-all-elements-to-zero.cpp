class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        int ans = 0;
        for(int &i :nums) {
            while(!st.empty() && st.top() > i) {
                st.pop();
                ans++;
            }
            if(st.top() != i) st.push(i);
        }
        while(st.top()) {
            ans++;
            st.pop();
        }
        return ans;
    }
};