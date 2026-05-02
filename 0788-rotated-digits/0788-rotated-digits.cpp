class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int j = i;
            bool changed = false, valid = true;
            while(j) {
                if(j % 10 == 2 || j % 10 == 5 || j % 10 == 6 || j % 10 == 9) {
                    changed = true;
                }
                else if(j % 10 == 3 || j % 10 == 4 || j % 10 == 7) {
                    valid = false;
                    break;
                }
                j /= 10;
            }
            if(changed & valid) ans++;
        }
        return ans;
    }
};