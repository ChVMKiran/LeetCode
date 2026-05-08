class Trie {
public:
    Trie* bit[2];
    int val;

    Trie() {
        bit[0] = bit[1] = nullptr;
    }
};

class Solution {
public:
    void insert(Trie* root, int val) {
        Trie* temp = root;
        bitset<32> bs(val);
        for(int i = 31; i >= 0; i--) {
            if(!temp->bit[bs[i]]) temp->bit[bs[i]] = new Trie();
            temp = temp->bit[bs[i]];
        }
    }

    int query(Trie* root, int val) {
        Trie* temp = root;
        bitset<32> bs(val);
        int v = 0;
        for(int i = 31; i >= 0; i--) {
            if(temp->bit[!bs[i]]) {
                temp = temp->bit[!bs[i]];
                v |= (!bs[i] << i);
            }
            else if(temp->bit[bs[i]]) {
                temp = temp->bit[bs[i]];
                v |= (bs[i] << i);
            }
        }
        return (v ^ val);
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        int ans = 0;
        for(int &n: nums) {
            insert(root, n);
            ans = max(ans, query(root, n));
        }
        return ans;
    }
};