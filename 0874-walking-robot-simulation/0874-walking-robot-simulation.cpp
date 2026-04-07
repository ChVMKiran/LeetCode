class Solution {
public:
    long long hash(long long x, long long y) {
        return x + 60010 * y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> ust;
        for(auto &obstacle: obstacles) {
            ust.insert(hash(obstacle[0], obstacle[1]));
        }
        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0; 
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int command : commands) {
            if (command == -1) {
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (ust.contains(hash(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                    currentPosition[1] * currentPosition[1]
                );
        }
        return maxDistanceSquared;
    }
};