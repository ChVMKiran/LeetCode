class Solution {
public:
    int minDiff = INT_MAX;
    vector<int> ans;
    void fun(vector<int>& divisors, vector<int>& curr, int n, int k) {
        if(k == 0) {
            if(n == 1) {
                int mini = *min_element(curr.begin(), curr.end());
                int maxi = *max_element(curr.begin(), curr.end());
                if(minDiff > maxi - mini) {
                    minDiff = maxi - mini;
                    ans = curr;
                }
            }
            return;
        }
        for(int &i: divisors) {
            if(i > n) break;
            if(n % i || (!curr.empty() && curr.back() < i)) continue;
            curr.push_back(i);
            fun(divisors, curr, n / i, k - 1);
            curr.pop_back();
        }
    }
    
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) divisors.push_back(i);
        }
        vector<int> curr;
        fun(divisors, curr, n, k);
        return ans;
    }
};