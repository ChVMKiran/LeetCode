class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), k = k1 + k2, maxDiff = 0;
        for(int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(nums1[i] - nums2[i]));
        }
        vector<int> mpp(maxDiff + 1);
        for(int i = 0; i < n; i++) {
            mpp[abs(nums1[i] - nums2[i])]++;
        }
        long long ans = 0;
        for(int i = maxDiff; i > 0; i--) {
            if(!mpp[i]) continue;
            int val = min(k, mpp[i]);
            mpp[i - 1] += val;
            mpp[i] -= val;
            k -= val;
            ans += (long long)mpp[i] * i * i;
            // if(mpp[i] <= k) {
            //     k -= mpp[i];
            //     mpp[i - 1] += mpp[i];
            // }
            // else {
            //     mpp[i] -= k;
            //     ans += (long long)(mpp[i]) * i * i;
            //     mpp[i - 1] += k;
            //     k = 0;
            // }
        }
        return ans;
    }
};