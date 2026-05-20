class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        ans[0] = A[0] == B[0];
        unordered_map<int, int> ump;
        ump[A[0]]++;
        ump[B[0]]--;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1];
            if(++ump[A[i]] == 0) ans[i]++;
            if(--ump[B[i]] == 0) ans[i]++;
        }
        ump.clear();
        return ans;
    }
};