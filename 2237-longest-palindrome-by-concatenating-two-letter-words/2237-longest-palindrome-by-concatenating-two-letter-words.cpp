class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        for(string &word :words) ump[word]++;
        int ans = 0;
        bool flag = true;
        for(auto &ele :ump) {
            string word = ele.first;
            int fre = ele.second;
            string rev = word;
            reverse(rev.begin(), rev.end());
            if(word[0] == word[1]) {
                ans += (ele.second / 2) * 2;
                if(ele.second % 2 && flag) {
                    ans++;
                    flag = false;
                }
            }
            else if(word < rev) {
                if(ump.count(rev)) ans += 2 * min(ump[rev], fre);
            }
        }
        return ans * 2;
    }
};