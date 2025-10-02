class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int e = numBottles;
        while (e >= numExchange) {
            numBottles++;
            e -= numExchange;
            e++;
            numExchange++;
        }
        return numBottles;
    }
};