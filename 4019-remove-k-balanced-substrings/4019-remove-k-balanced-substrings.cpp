class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;
        for(char &ch: s) {
            if(!st.empty() && st.back().first == ch) st.back().second++;
            else st.push_back({ch, 1});
            int len = st.size();
            if(len > 1 && st[len - 2].first == '(' && 
            st[len - 2].second >= k && st[len - 1].first == ')' && 
            st[len - 1].second == k) {
                st.pop_back();
                st.back().second -= k;
                if(st.back().second == 0) st.pop_back();
            }
        }
        string ans;
        for(auto &ch: st) {
            ans += string(ch.second, ch.first);
        }
        return ans;
    }
};