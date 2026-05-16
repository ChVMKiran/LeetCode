class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int m = l + (h - l) / 2;

            if (nums[m] < nums[h]) { // right sorted -> discard
                h = m;
            }
            else if (nums[m] > nums[h]) { // min exists in right only
                l = m + 1;
            }
            else { // ambiguos so move h
                h--;
            }
        }

        return nums[l];
    }
};

// @chatgpt code