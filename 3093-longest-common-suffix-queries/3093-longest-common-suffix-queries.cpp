class Solution {
public:

    struct Trie {
        Trie* next[26];
        int idx;
        int len;

        Trie() {
            idx = INT_MAX;
            len = INT_MAX;
            fill(next, next + 26, nullptr);
        }
    };

    Trie* root = new Trie();

    void insert(string word, int originalLen, int idx) {
        Trie* cur = root;
        for(int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if(cur->next[ch] == nullptr) {
                cur->next[ch] = new Trie();
            }
            cur = cur->next[ch];
            if(cur->len > originalLen) {
                cur->len = originalLen;
                cur->idx = idx;
            }
        }
    }

    int search(string &word) {
        Trie* cur = root;
        for(int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if(cur->next[ch] == nullptr) {
                break;
            }
            cur = cur->next[ch];
        }
        return cur->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int maxQueryLen = 0, m = wordsQuery.size();
        for(auto &q : wordsQuery) {
            maxQueryLen = max(maxQueryLen, (int)q.size());
        }

        for(int i = 0; i < wordsContainer.size(); i++) {
            string &word = wordsContainer[i];
            int start = max(0, (int)word.size() - maxQueryLen);
            insert(word.substr(start), word.size(), i);
            if(root->len > word.size()) {
                root->len = word.size();
                root->idx = i;
            }
        }
        
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = search(wordsQuery[i]);
        }
        return ans;
    }
};