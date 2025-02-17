class Solution {
public:
    int numTilePossibilities(string tiles) {
        int freq[26]={0};
        for(int i=tiles.length()-1;i>=0;i--)freq[tiles[i]-'A']++;
        return solve(freq);
    }
    int solve(int freq[]){
        int count=0;
        for(int i=0;i<26;i++){
            if(!freq[i])continue;
            freq[i]--;
            count++;
            count+=solve(freq);
            freq[i]++;
        }
        return count;
    }
};