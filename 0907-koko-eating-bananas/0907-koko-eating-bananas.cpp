class Solution {
public:
    bool helper(vector<int>& piles, int mid, int h) {
        int cnt = 0;
        for(int &pile :piles) {
            cnt += (pile + mid - 1) / mid;
            if(cnt > h) return false;
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(), piles.end());
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(helper(piles, mid, h)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};