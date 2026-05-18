class Solution {
    int n;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, unordered_map<string, int>& ump, vector<string>& vec) {
        if(word == b) {
            reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            reverse(vec.begin(), vec.end());
            return;
        }
        for(int i = 0; i < n; i++) {
            string org = word;
            for(char j = 'a'; j <= 'z'; j++) {
                org[i] = j;
                if(ump.count(org) && ump[org] == ump[word] - 1) {
                    vec.push_back(org);
                    dfs(org, ump, vec);
                    vec.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> ump;
        queue<string> qu;
        unordered_set<string> ust(wordList.begin(), wordList.end());
        ump[beginWord] = 0;
        qu.push(beginWord);
        ust.erase(beginWord);
        n = beginWord.size();
        b = beginWord;
        while(!qu.empty()) {
            auto word = qu.front();
            int steps = ump[word];
            if(word == endWord) break;
            qu.pop();
            for(int i = 0; i < n; i++) {
                string org = word;
                for(char j = 'a'; j <= 'z'; j++) {
                    org[i] = j;
                    if(ust.count(org)) {
                        qu.push(org);
                        ump[org] = steps + 1;
                        ust.erase(org);
                    }
                }
            }
        }
        vector<string> vec = {endWord};
        if(ump.count(endWord)) dfs(endWord, ump, vec);
        return ans;
    }
};