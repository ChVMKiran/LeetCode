class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> ump;
        for(char &ch: word) {
            ump[ch]++;
        }
        int ans = word.size();
        for(auto &[ele1, freq1] : ump) {
            int curr = 0;
            for(auto &[ele2, freq2] : ump) {
                if(freq2 < freq1) curr += freq2;
                else if(freq2 > freq1 + k) curr += (freq2 - freq1 - k);
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};