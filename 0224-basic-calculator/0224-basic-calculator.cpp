class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1, n = s.size(), num = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '+' || s[i] == '-') {
                ans += num * sign;
                num = 0;
                sign = s[i] == '+' ? 1 : -1;
            }
            else if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                ans += (num * sign);
                ans *= st.top();
                st.pop();
                ans += st.top();
                st.pop();
                num = 0;
            }
        }
        ans += num * sign;
        return ans;
    }
};