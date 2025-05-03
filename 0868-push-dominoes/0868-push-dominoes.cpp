class Solution {
public:
    string pushDominoes(string dominoes) {
        int lastRight = -1, lastLeft = -1, n = dominoes.size();
        string ans = dominoes;
        for(int i = 0; i <  n; i++) {
            if(dominoes[i] == 'R') lastRight = i;
            else if(dominoes[i] == 'L') {
                if(lastRight == -1) {
                    int j = i;
                    while(j-- && ans[j] == '.') ans[j] = 'L';
                }
                else {
                    int len = (i - lastRight - 1) / 2; 
                    int val = i - len;
                    if(lastLeft != -1 && lastLeft > lastRight) val = min(lastLeft + 1, val);
                    for(int j = i - 1; j >= val && ans[j] == '.'; j--) ans[j] = 'L';
                    // cout<<lastLeft;
                }
                lastLeft = i;
            }
        }
        lastLeft = -1, lastRight = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(dominoes[i] == 'L') lastLeft = i;
            else if(dominoes[i] == 'R') {
                // cout<<lastLeft<<i<<'\n';
                if(lastLeft == -1) {
                    int j = i + 1;
                    // cout<<i<<n<<'\n'<<ans<<'\n';
                    while(j < n && ans[j] == '.') {
                        // cout<<0;
                        ans[j++] = 'R';
                    }
                    // cout<<ans<<'\n';
                }
                else {
                    int len = (lastLeft - i - 1) / 2;
                    int val = i + len;
                    if(lastRight != -1 && lastLeft > lastRight) val = max(lastRight, val);
                    for(int j = i + 1; j <= val && ans[j] == '.'; j++) ans[j] = 'R';
                }
                lastRight = i;
            }
        }
        return ans;
    }
};