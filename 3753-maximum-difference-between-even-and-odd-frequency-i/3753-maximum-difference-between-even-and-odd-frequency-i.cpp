class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for(char &ch: s) {
            freq[ch - 'a']++;
        }
        int leastOdd = 101, leastEven = 101, mostOdd = 0, mostEven = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                if(freq[i] % 2) {
                    mostOdd = max(freq[i], mostOdd);
                    leastOdd = min(freq[i], leastOdd);
                }
                else{
                    mostEven = max(freq[i], mostEven);
                    leastEven = min(freq[i], leastEven);
                }
            }
        }
        if(!mostEven || !mostOdd) return s.size();
        return max((mostOdd - leastEven), (leastOdd - mostEven));
    }
};