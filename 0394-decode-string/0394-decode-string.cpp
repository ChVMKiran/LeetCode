class Solution {
public:
    string decodeString(string s) {
        int n = s.size(), curr = 0;
        stack<pair<int, string>> st;
        st.push({1, ""});
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                curr = curr * 10 + s[i] - '0';
            }
            else if(s[i] == '[') {
                st.push({curr, ""});
                curr = 0;
            }
            else if(s[i] != ']') {
                st.top().second += s[i];
            }
            else {
                auto [rep, txt] = st.top();
                st.pop();
                string res;
                while(rep--) st.top().second += txt;
            }
        }
        return st.top().second;
    }
};