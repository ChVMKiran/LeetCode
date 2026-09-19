class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int freq[26]{}, n = s.size();
        int first[26], last[26];
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);
        for(int i = 0; i < n; i++) {
            if(!freq[s[i] - 'a']) first[s[i] - 'a'] = i;
            freq[s[i] - 'a']++;
            last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> intervals;
        for(int i = 0; i < 26; i++) {
            if(first[i] == -1) continue;
            int l = first[i];
            int r = last[i];
            bool valid = true;
            for(int j = l; j <= r; j++) {
                int c = s[j] - 'a';
                if(first[c] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }
            if(valid) {
                intervals.push_back({r, l});
            }
        }
        sort(intervals.begin(), intervals.end());
        vector<string> ans;
        int prev = -1;
        for(auto& [r, l]: intervals) {
            if(prev > l) continue;
            ans.push_back(s.substr(l, r - l + 1));
            prev = r;
        }
        return ans;
    }
};