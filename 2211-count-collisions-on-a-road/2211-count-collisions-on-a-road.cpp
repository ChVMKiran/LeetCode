class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), right = 0, ans = 0, still = 0;
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'R') right++;
            else if(directions[i] == 'L') {
                if(right) {
                    ans += (right + 1);
                    right = 0;
                    still = 1;
                }
                else if(still) ans++;
            }
            else {
                still = 1;
                if(right) ans += right;
                right = 0;
            }
        }
        return ans;
    }
};