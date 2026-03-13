class Solution {
public:
    using ll = long long;
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll ans = 0;
        int n = workerTimes.size(), maxi = *max_element(workerTimes.begin(), workerTimes.end());
        ll low = 1, high = 1ll * maxi * mountainHeight * (mountainHeight + 1) / 2;
        while(low < high) {
            ll mid = (low + high) >> 1, val = 0;
            for(auto &ele: workerTimes) {
                val += sqrt((2 * mid) / ele + 0.25) - 0.5;
                if(val >= mountainHeight) break;
            }
            if(val >= mountainHeight) high = mid;
            else low = mid + 1;
        }
        return high;
    }
};