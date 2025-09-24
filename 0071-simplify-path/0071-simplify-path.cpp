class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int n = path.size();
        stack<string> st;
        for(int i = 0; i < n; i++) {
            if(path[i] == '/') continue;
            string curr;
            while(i < n && path[i] != '/') curr += path[i++];
            if(curr == ".") continue;
            else if(curr == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(curr);
        }
        while(!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        return ans.size() ? ans : "/";
    }
};