class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> ump;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        for(int &i: nums2) ump[i]++;
    }
    
    void add(int index, int val) {
        ump[nums2[index]]--;
        nums2[index] += val;
        ump[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int &i: nums1) {
            ans += ump[tot - i];
        }
        return ans;
    }
};
