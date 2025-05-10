class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeroes1 = 0, zeroes2 = 0;
        for(int &i :nums1) {
            sum1 += i;
            if(!i) zeroes1++;
        }
        for(int &i :nums2) {
            sum2 += i;
            if(!i) zeroes2++;
        }
        if(sum1 == sum2) {
            if(zeroes1 && zeroes2) return sum1 + max(zeroes1, zeroes2);
            if(zeroes1 || zeroes2) return -1;
            return sum1;
        }
        else{
            if(!zeroes1 && !zeroes2) return -1;
            if(sum1 > sum2) {
                if(!zeroes2) return -1;
                if(!zeroes1 && sum1 < sum2 + zeroes2) return -1;
                return max(sum1 + zeroes1, sum2 + zeroes2);
            }
            else {
                if(!zeroes1) return -1;
                if(!zeroes2 && sum2 < sum1 + zeroes1) return -1;
                return max(sum1 + zeroes1, sum2 + zeroes2);
            }
        }
    }
};