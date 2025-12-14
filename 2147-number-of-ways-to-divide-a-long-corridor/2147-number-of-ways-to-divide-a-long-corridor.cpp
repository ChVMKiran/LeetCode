class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7, ans = 1, seats = 0, plants = 0;
        // cout<<corridor.size();
        for(char &c: corridor) {
            if(c == 'S') {
                seats++;
                if(seats % 2 == 1 && seats > 1) {
                    ans = ((long long)ans * (plants + 1)) % mod;
                    plants = 0;
                }
                else plants = 0;
            }
            else plants++;
            // cout<<ans<<' ';
        }
        if(seats % 2 || seats < 2) return 0;
        return ans;
    }
};