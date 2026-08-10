class Solution {
public:
    inline static const int MAXN = 100001;
    inline static bitset<MAXN + 1> bs;
    inline static bool init = []() {
        for(int i = 0; i <= MAXN; i++) {
            if(bs.test(i)) continue;
            for(int j = 1; i + j * j <= MAXN; j++) {
                bs.set(i + j * j);
            }
        }
        return false;
    }();
    bool winnerSquareGame(int n) { return bs.test(n); }
};