class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust(wordList.begin(), wordList.end());
        if(!ust.count(endWord)) return 0;
        int n = beginWord.size();
        queue<pair<string, int>> qu;
        qu.push({beginWord, 1});
        ust.erase(beginWord);
        while(!qu.empty()) {
            auto [word, dist] = qu.front();
            if(word == endWord) return dist;
            qu.pop();
            for(int i = 0; i < n; i++) {
                string dup = word;
                for(int j = 0; j < 26; j++) {
                    dup[i] = 'a' + j;
                    if(ust.count(dup)) {
                        qu.push({dup, dist + 1});
                        ust.erase(dup);
                    }
                }
            }
        }
        return 0;
    }
};