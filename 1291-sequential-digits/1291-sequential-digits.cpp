class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = log10(low), ten = pow(10, i - 1); i <= log10(high); i++) {
            int curr = 1, cnt = 1;
            ten *= 10;
            while(cnt <= i) curr = curr * 10 + curr % 10 + 1, cnt++;
            while(curr % 10) {
                if(curr <= high) {
                    if(curr >= low) ans.push_back(curr);
                }
                else break;
                curr = (curr % ten) * 10 + curr % 10 + 1;
            }
        }
        return ans;
    }
};