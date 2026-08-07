class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for(int i = 2; i <= 7; i++) {
            while(temp % i == 0) temp /= i;
            if(i != 2) i++;
        }
        if(temp > 1) return "-1";
        int n = num.size(), pos = n - 1;
        vector<long long> rem(n + 1);
        rem[0] = t;
        for(int i = 0; i < n; i++) {
            if(num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], (num[i] - '0'));
        }
        if(rem[n] == 1) return num;
        for(int i = pos; i >= 0; i--) {
            while(++num[i] <= '9') {
                long long curr = rem[i] / gcd(rem[i], (num[i] - '0'));
                int k = 9;
                for(int j = n - 1; j > i; j--) {
                    while(curr % k) k--;
                    curr /= k;
                    num[j] = (k + '0');
                }
                if(curr == 1) return num;
            }
        }
        string ans;
        for(int i = 9; i >= 2; i--) {
            while(t % i == 0) {
                ans += (i + '0');
                t /= i;
            }
        }
        while(ans.size() <= num.size()) {
            ans += '1';
        }
        ranges::reverse(ans);
        return ans;
    }
};