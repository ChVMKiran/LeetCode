class Solution {
public:
    bool helper(vector<int>& arr1, vector<int>& arr2) {
        if(arr1 == arr2) return true;
        int n = arr1.size();
        for(int i = 0; i < n - 1; i++) {
            if(arr1[i] > arr1[i + 1]) {
                vector<int> curr;
                curr.insert(curr.begin(), arr1.begin() + i + 1, arr1.end());
                curr.insert(curr.end(), arr1.begin(), arr1.begin() + i + 1);
                return curr == arr2;
            }
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> fac;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                fac.push_back(i);
                if(n / i != i) fac.push_back(n / i);
            }
        }
        vector<int> tar = nums;
        ranges::sort(tar);
        for(int& f: fac) {
            bool flag = true;
            for(int i = 0; i < n; i += f) {
                int j = i + f;
                vector<int> sub1(nums.begin() + i, nums.begin() + j);
                vector<int> sub2(tar.begin() + i, tar.begin() + j);
                if(!helper(sub1, sub2)) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += f;
        }
        return ans;
    }
};