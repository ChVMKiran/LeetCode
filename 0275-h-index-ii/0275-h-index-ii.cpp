class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int mini = 0, maxi = n;
        while(mini < maxi) {
            int mid = mini + (maxi - mini) / 2;
            if(citations[mid] < n - mid) mini = mid + 1;
            else maxi = mid;
        }
        return n - mini;
    }
};