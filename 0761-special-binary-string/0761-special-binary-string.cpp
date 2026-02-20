class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        vector<string> strs;
        int cnt = 0;
        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == '1') cnt++;
            else cnt--;
            if(cnt == 0) {
                strs.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(strs.begin(),strs.end(), greater<string>());
        string ans;
        for(auto& str: strs) {
            ans += str;
        }
        return ans;
    }
};