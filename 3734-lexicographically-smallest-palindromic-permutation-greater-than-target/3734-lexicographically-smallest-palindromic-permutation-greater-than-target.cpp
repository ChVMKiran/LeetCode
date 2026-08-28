class Solution {
public:
    string res = "", mid = "";
    bool helper(string& curr, int freq[], string &target, int ind, bool flag) {
        if(ind == target.size() / 2) {
            string rev = curr;
            ranges::reverse(rev);
            if(target < curr + mid + rev) {
                res = curr + mid + rev;
                return true;
            }
            return false;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(!flag && target[ind] > i + 'a') continue;
            curr += (i + 'a');
            freq[i]--;
            if(helper(curr, freq, target, ind + 1, flag || target[ind] < i + 'a'))
                return true;
            curr.pop_back();
            freq[i]++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int freq[26] = {0};
        for(auto& c: s) freq[c - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2) {
                if(mid != "") return "";
                mid = i + 'a';
            }
            freq[i] >>= 1;
        }
        string curr;
        helper(curr, freq, target, 0, false);
        return res;
    }
};