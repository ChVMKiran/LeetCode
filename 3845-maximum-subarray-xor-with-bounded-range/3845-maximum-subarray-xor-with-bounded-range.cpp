class Trie {
  public:
    int cnt;
    Trie* arr[2];
    Trie() {
        cnt = 0;
        arr[0] = arr[1] = nullptr;
    }
};

void insert(int n, Trie* root) {
    Trie* temp = root;
    temp->cnt++;
    for(int i = 15; i >=0 ; i--) {
        int b = (n >> i) & 1;
        if(!temp->arr[b]) {
            temp->arr[b] = new Trie();
        }
        temp = temp->arr[b];
        temp->cnt++;
    }
}

void remove(int n, Trie* root) {
    Trie* temp = root;
    temp->cnt--;
    for(int i = 15; i >= 0; i--) {
        int b = (n >> i) & 1;
        temp = temp->arr[b];
        temp->cnt--;
    }
}

int query(int n, Trie* root) {
    Trie* temp = root;
    int val = 0;
    for(int i = 15; i >= 0; i--) {
        int b = (n >> i) & 1;
        val <<= 1;
        if(temp->arr[!b] && temp->arr[!b]->cnt > 0) {
            temp = temp->arr[!b];
            val++;
        }
        else if(temp->arr[b] && temp->arr[b]->cnt > 0) {
            temp = temp->arr[b];
        }
    }
    return val;
}

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        Trie *root = new Trie();
        insert(0, root);
        deque<int> minis, maxis;
        vector<int> pre(n);
        for(int left = 0, right = 0; right < n; right++) {
            pre[right] ^= nums[right];
            if(right) pre[right] ^= pre[right - 1];
            while(!minis.empty() && nums[minis.back()] >= nums[right]) minis.pop_back();
            while(!maxis.empty() && nums[maxis.back()] <= nums[right]) maxis.pop_back();
            minis.push_back(right);
            maxis.push_back(right);
            int mini = nums[minis.front()], maxi = nums[maxis.front()];
            while(maxi - mini > k) {
                if(left) remove(pre[left - 1], root);
                else remove(0, root);
                if(left == minis.front()) minis.pop_front();
                if(left == maxis.front()) maxis.pop_front();
                if(minis.empty() || maxis.empty()) break;
                mini = nums[minis.front()], maxi = nums[maxis.front()];
                left++;
            }
            ans = max(ans, query(pre[right], root));
            insert(pre[right], root);
        }
        return ans;
    }
};