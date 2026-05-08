class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size(), maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= maxi; i++) {
            if(isPrime[i]) {
                for(int j = i + i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        unordered_map<int, vector<int>> ump;
        for(int i = 0; i < n; i++) {
            ump[nums[i]].push_back(i);
        }
        queue<pair<int, int>> qu;
        vector<int> jumps(n, -1);
        qu.push({0, 0});
        jumps[0] = 0;
        while(!qu.empty()) {
            auto [i, t] = qu.front();
            qu.pop();
            if(i > 0 && jumps[i - 1] == -1) {
                jumps[i - 1] = t + 1;
                qu.push({i - 1, t + 1});
            }
            if(i < n - 1 && jumps[i + 1] == -1) {
                if(i == n - 1) return t + 1;
                jumps[i + 1] = t + 1;
                qu.push({i + 1, t + 1});
            }
            if(isPrime[nums[i]]) {
                for(int j = nums[i]; j <= maxi; j += nums[i]) {
                    for(auto& a: ump[j]) {
                        if(jumps[a] == -1) {
                            if(a == n - 1) return t + 1;
                            jumps[a] = t + 1;
                            qu.push({a, t + 1});
                        }
                    }
                }
                isPrime[nums[i]] = false;
            }
        }
        return jumps[n - 1];
    }
};