class Solution {
public:
    vector<int> fun(int n) {
        vector<int> digitFreq(10, 0);
        while(n) {
            digitFreq[n % 10]++;
            n /= 10;
        }
        return digitFreq;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> digitFreq = fun(n);
        for(int i = 0; i < 31; i++) {
            vector<int> curr = fun(1 << i);
            if(digitFreq == curr) return true;
        }
        return false;
    }
};