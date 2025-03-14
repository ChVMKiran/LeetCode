class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 0, high = *max_element(candies.begin(), candies.end());
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(mid == 0) low = 1;
            else if(isPossible(candies, mid, k)) {
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }
        return low - 1;
    }

private:
    bool isPossible(vector<int> &candies, int candies_per_student, long long k) {
        long long count = 0;
        for(int &i :candies) {
            count += i/candies_per_student;
        }
        return k <= count;
    }
};