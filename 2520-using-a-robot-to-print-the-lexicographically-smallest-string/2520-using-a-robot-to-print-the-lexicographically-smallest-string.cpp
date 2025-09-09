class Solution {
public:
    string robotWithString(string s) {
        string ans;
        int n = s.size();
        stack<char> st;
        vector<int> freq(26);
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        char curr = 'a';
        for(int i = 0; i < n; i++) {
            st.push(s[i]);
            freq[s[i] - 'a']--;
            while(curr < 'z' && freq[curr - 'a'] == 0) curr++;
            while(!st.empty() && st.top() <= curr) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};