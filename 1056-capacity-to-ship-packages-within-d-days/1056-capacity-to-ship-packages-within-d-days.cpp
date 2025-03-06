class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int weight){
        int count = 1, curr = 0;
        for(int &i:weights){
            curr += i;
            if(curr > weight){
                curr = i;
                count++;
            }
        }
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0, sum = 0, n = weights.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        int ans = sum;
        while(maxi <= sum){
            int mid = (maxi+sum)/2;
            if(isPossible(weights, days, mid)){
                sum = mid - 1;
                ans = min(ans, mid);
            }
            else{
                maxi = mid + 1;
            }
        }
        return ans;
    }
};