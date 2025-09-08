class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), i = 0, j = 1;
        stack<int> st;
        st.push(i);
        while(j < n) {
            int cnt = -1;
            while(!st.empty() && nums[st.top()] < nums[j]) {
                st.pop();
                cnt++;
            }
            if(cnt > 0) ans += cnt;
            if(!st.empty() && j - st.top() + 1 >= 3) ans++;
            st.push(j);
            j++;
        }
        return ans;
    }
};