class Solution {
private:
    vector<vector<int>> ans;
    void rec(vector<int>& arr, vector<int>& curr, int ind, int val) {
        if(val == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = ind; i < arr.size() && arr[i] <= val; i++) {
            if(i > ind && arr[i] == arr[i - 1]) continue;
            curr.push_back(arr[i]);
            rec(arr, curr, i + 1, val - arr[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        rec(candidates, curr, 0, target);
        return ans;
    }
};