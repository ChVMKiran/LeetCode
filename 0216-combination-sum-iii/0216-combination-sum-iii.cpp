class Solution {
private:
    vector<vector<int>> ans;
    void rec(vector<int>& curr, int k, int st, int n) {
        if(curr.size() == k) {
            if(n == 0) ans.push_back(curr);
            return;
        }
        for(int i = st; i < 10 && n >= i; i++) {
            curr.push_back(i);
            rec(curr, k, i + 1, n - i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        for(int i = 1; i < 10 && n >= i; i++) {
            curr.push_back(i);
            rec(curr, k, i + 1, n - i);
            curr.pop_back();
        }
        return ans;
    }
};