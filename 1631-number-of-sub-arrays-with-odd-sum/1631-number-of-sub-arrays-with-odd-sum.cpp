class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long ans = 0, sum = 0;
        int evens = 1, odds = 0, n = arr.size(), mod = 1e9+7;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum%2){
                ans += evens;
                odds++;
            }
            else{
                ans += odds;
                evens++;
            }
            ans = ans%mod;
        }
        return ans;
    }
};