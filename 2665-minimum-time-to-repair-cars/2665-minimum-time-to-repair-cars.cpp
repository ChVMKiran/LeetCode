class Solution {
private:
    int n;
    bool isPossible(vector<int>& ranks, long long time, int cars) {
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += sqrt(time / ranks[i]);
        }
        return cnt >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        n = ranks.size();
        long long low = 1, high = 1LL * ranks[0] * cars * cars;
        while (low <= high) {
            long long mid = (low + high) >> 1;
            if(isPossible(ranks, mid, cars)) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high + 1;
    }
};