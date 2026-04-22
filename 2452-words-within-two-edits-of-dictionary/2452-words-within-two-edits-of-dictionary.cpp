class Trie {
public:
    bool isEnd;
    Trie* childs[26];
    Trie() {
        isEnd = false;
        memset(childs, 0, sizeof(childs));
    }
};

class Solution {
public:
    Trie* root = new Trie();
    void insert(string& word) {
        Trie* temp = root;
        for(char& c: word) {
            if(!temp->childs[c - 'a']) temp->childs[c - 'a'] = new Trie();
            temp = temp->childs[c - 'a'];
        }
        temp->isEnd = true;
    }

    bool search(string& word, int ind, Trie* temp, int cnt) {
        if(ind >= word.size()) return true;
        // without edit
        if(temp->childs[word[ind] - 'a'] && 
        search(word, ind + 1, temp->childs[word[ind] - 'a'], cnt)) return true;
        // with edit 
        if(cnt < 2) {
            for(int i = 0; i < 26; i++) {
                if(i == word[ind] - 'a') continue;
                if(temp->childs[i] && 
                search(word, ind + 1, temp->childs[i], cnt + 1)) return true;
            }
        }
        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto& word: dictionary) insert(word);
        for(auto& word: queries) {
            if(search(word, 0, root, 0)) ans.push_back(word);
        }
        return ans;
    }
};