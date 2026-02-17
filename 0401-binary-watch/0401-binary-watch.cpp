class Solution {
public:
    int setBits(int n) {
        int res = 0;
        while(n) {
            if(n & 1) res++;
            n >>= 1;
        }
        return res;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        unordered_map<int, vector<int>> ump;
        for(int i = 0; i < 60; i++) {
            ump[setBits(i)].push_back(i);
        }
        for(int i = 0; i <= turnedOn; i++) {
            if(i >= 4 || turnedOn - i >= 6) continue;
            for(auto& h: ump[i]) {
                if(h > 11) continue;
                for(auto& m: ump[turnedOn - i]) {
                    ans.push_back(to_string(h) + ':' + (m > 9 ? to_string(m) : '0' + to_string(m)));
                }
            }
        }
        return ans;
    }
};