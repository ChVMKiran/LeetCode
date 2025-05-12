class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int n = digits.size();
        vector<int> ans, freq(10, 0);
        for(int i = 0; i < n; i++) {
            freq[digits[i]]++;
        }
        for(int i = 1; i < 10; i++) {
            if(!freq[i]) continue;
            freq[i]--;
            for(int j = 0; j < 10; j++) {
                if(!freq[j]) continue;
                freq[j]--;
                for(int k = 0; k < 10; k += 2) {
                    if(freq[k]) ans.push_back(i * 100 + j * 10 + k);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};