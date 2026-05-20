class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<int> ans(n);
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            if(++ump[A[i]] == 0) {
                cnt++;
                ump.erase(A[i]);
            }
            if(--ump[B[i]] == 0) {
                cnt++;
                ump.erase(B[i]);
            }
            ans[i] = cnt;
        }
        return ans;
    }
};