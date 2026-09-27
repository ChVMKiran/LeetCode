class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for(int i = 0; s[i]; i++) {
            if(s[i] == '(') {
                st.push(res.length());
            }
            else if(s[i] == ')') {
                int sz = st.top();
                st.pop();
                reverse(res.begin() + sz, res.end());
            }
            else res += s[i];
        }
        return res;
    }
};