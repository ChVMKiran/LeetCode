class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int val1 = 0, val2 = 0, n = moves.size();
        for(char&c : moves) {
            if(c == 'L') {
                val1--;
                val2--;
            }
            else if(c == 'R') {
                val1++;
                val2++;
            }
            else {
                val1--;
                val2++;
            }
        }
        return max(-val1, val2);
    }
};