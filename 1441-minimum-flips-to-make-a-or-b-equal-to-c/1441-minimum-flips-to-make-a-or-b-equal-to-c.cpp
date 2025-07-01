class Solution {
public:
    int minFlips(int a, int b, int c) {
        string s1 = bitset<32>(a).to_string();
        string s2 = bitset<32>(b).to_string();
        string s3 = bitset<32>(c).to_string();
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(s3[i] == '0') {
                if(s1[i] == '1') ans++;
                if(s2[i] == '1') ans++;
            }
            else if(s1[i] == '0' && s2[i] == '0') ans ++;
        }
        return ans;
    }
};
// 1000 0011
// 0101