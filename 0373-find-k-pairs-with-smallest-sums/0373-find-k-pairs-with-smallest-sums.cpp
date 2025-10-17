class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                if(pq.size() == k) {
                    if(pq.top().first > nums1[i] + nums2[j]) pq.pop();
                    else break;
                }
                pq.push({(nums1[i] + nums2[j]), {i, j}});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto [i1, i2] = pq.top().second;
            pq.pop();
            ans.push_back({nums1[i1], nums2[i2]});
        }
        return ans;
    }
};