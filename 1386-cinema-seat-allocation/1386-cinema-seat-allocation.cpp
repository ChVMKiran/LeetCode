class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2 * n;
        unordered_map<int, vector<bool>> ump;
        for (auto& seat : reservedSeats) {
            if (seat[1] % 9 == 1)
                continue; // seat no 1 & 10
            if (ump[seat[0]].empty())
                ump[seat[0]] = vector<bool>(11);
            ump[seat[0]][seat[1]] = true;
        }
        for (auto& [k, v] : ump) {
            bool left = (v[2] == 0 && v[3] == 0 && v[4] == 0 && v[5] == 0);
            bool mid = (v[4] == 0 && v[5] == 0 && v[6] == 0 && v[7] == 0);
            bool right = (v[6] == 0 && v[7] == 0 && v[8] == 0 && v[9] == 0);

            if (left && right) continue;
            else if (left || mid || right) ans--;
            else ans -= 2;
        }
        return ans;
    }
};