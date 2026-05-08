class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 4; i <= maxi; i += 2) isPrime[i] = 0;
        for(int i = 3; i * i <= maxi; i += 2) {
            if(isPrime[i]) {
                for(int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<vector<int>> ump(maxi + 1);
        for(int i = 0; i < n; i++) {
            ump[nums[i]].push_back(i);
        }
        queue<pair<int, int>> qu;
        vector<bool> vis(n);
        qu.push({0, 0});
        vis[0] = true;
        while(!qu.empty()) {
            auto [i, t] = qu.front();
            qu.pop();
            if(i > 0 && !vis[i - 1]) {
                vis[i - 1] = true;
                qu.push({i - 1, t + 1});
            }
            if(i < n - 1 && !vis[i + 1]) {
                if(i + 1 == n - 1) return t + 1;
                vis[i + 1] = true;
                qu.push({i + 1, t + 1});
            }
            if(isPrime[nums[i]]) {
                for(int j = nums[i]; j <= maxi; j += nums[i]) {
                    for(int a: ump[j]) {
                        if(!vis[a]) {
                            if(a == n - 1) return t + 1;
                            vis[a] = true;
                            qu.push({a, t + 1});
                        }
                    }
                    ump[j].clear();
                }
                isPrime[nums[i]] = false;
            }
        }
        return 0;
    }
};