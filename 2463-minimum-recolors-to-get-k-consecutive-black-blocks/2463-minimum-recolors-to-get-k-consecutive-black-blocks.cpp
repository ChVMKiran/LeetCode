class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(),currWhites = 0;
        for(int i = 0; i < k; i++) {
            if(blocks[i] == 'W')currWhites++;
        }
        int minWhites = currWhites;
        for(int i = k; i < n; i++) {
            if(blocks[i] == 'W')currWhites++;
            if(blocks[i - k] == 'W')currWhites--;
            minWhites = min(minWhites, currWhites);
        }
        return minWhites;
    }
};