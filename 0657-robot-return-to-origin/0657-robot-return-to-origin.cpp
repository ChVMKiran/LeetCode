class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto& move: moves) {
            switch(move) {
                case 'U': 
                    y++;
                    break;
                case 'D': 
                    y--;
                    break;
                case 'L': 
                    x++;
                    break;
                default:
                    x--;
            }
        }
        return x == 0 && y == 0;
    }
};