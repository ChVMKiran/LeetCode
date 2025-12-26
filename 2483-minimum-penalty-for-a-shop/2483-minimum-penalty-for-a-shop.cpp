class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0, val = 0, curr = 0, n = customers.size();
        for(int i = 0; i < n; i++) {
            val += (customers[i] == 'Y');
        }
        curr = val;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') curr--;
            else curr++;
            if(curr < val) {
                val = curr;
                ans = i + 1;
            }
        }
        return ans;
    }
};