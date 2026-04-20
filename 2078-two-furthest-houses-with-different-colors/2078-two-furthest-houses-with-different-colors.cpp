class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        for(int i = 0; i < n; i++) {
            if(colors[n - i - 1] != colors[0] || colors[n - 1] != colors[i]) 
                return n - i - 1;
        }
        return -1;
    }
};