class Solution {
public:
    char findKthBit(int n, int k) {
        int cnt = 0;
        while(k > 1) {
            if((1<<(n - 1)) == k) {
                cnt++; 
                break;
            }
            else if(1<<(n - 1) < k) cnt++, k = ((1<<n) - k);
            n--;
        }
        return cnt % 2 ? '1' : '0';
    }
};