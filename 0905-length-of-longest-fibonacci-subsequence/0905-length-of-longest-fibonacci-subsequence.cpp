class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> ust(arr.begin(), arr.end());
        int ans = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int a = arr[i], b = arr[j], c = a + b, curr = 2;
                while(ust.find(c)!=ust.end()){
                    a = b;
                    b = c;
                    c = a + b;
                    curr++;
                }
                if(curr > 2) ans = max(ans, curr);
            }
        }
        return ans;
    }
};