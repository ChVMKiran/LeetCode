class Solution {
public:
    long long limit, total;
    
    long long comb(int n, int r) {
        r = min(r, n - r);
        long long res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if(res > limit) return limit + 1;
        }
        return res;
    }

    long long countWays(int freq[]) {
        long long res = 1;
        for(int i = 0, prev = 0; i < 26; i++) {
            if(!freq[i]) continue;
            res *= comb(total - prev, freq[i]);
            if(res > limit) return limit + 1;
            prev += freq[i];
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        total = n / 2;
        limit = k;
        int freq[26] = {0};
        for(int i = 0; i < n / 2; i++) freq[s[i] - 'a']++;
        if(countWays(freq) < k) return "";
        string left, mid, right;
        if(n % 2) mid = s[n / 2];
        for(int i = 0; i < n / 2; i++) {
            total--;
            int curr = 0;
            for(int j = 0; j < 26; j++) {
                if(!freq[j]) continue;
                freq[j]--;
                int ways = countWays(freq);
                if(curr + ways >= k) {
                    k -= curr;
                    left += (j + 'a');
                    break;
                }
                curr += ways;
                freq[j]++;
            }
        }
        right = left;
        ranges::reverse(right);
        return left + mid + right;
    }
};