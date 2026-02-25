class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int a, int b) {
            int cnt1 = 0, cnt2 = 0, a1 = a, b1 = b;
            while(a) {
                a = a & (a - 1);
                cnt1++;
            }
            while(b) {
                b = b & (b - 1);
                cnt2++;
            }
            if(cnt1 == cnt2) return a1 < b1;
            return cnt1 < cnt2;
        });
        return arr;
    }
};