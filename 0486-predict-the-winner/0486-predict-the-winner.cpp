class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        map<vector<int>, bool> ump;
        function<bool(int, int, int, int)> helper = [&](int i, int j, int turn, int sum) {
            if(i > j) return sum >= 0;
            if(ump.count({i, j, turn, sum})) return ump[{i, j, turn, sum}];
            if(turn) {
                return ump[{i, j, turn, sum}] = (
                    helper(i + 1, j, !turn, sum - nums[i])
                    && helper(i, j - 1, !turn, sum - nums[j])
                );
            }
            else {
                return ump[{i, j, turn, sum}] = (
                    helper(i + 1, j, !turn, sum + nums[i])
                    || helper(i, j - 1, !turn, sum + nums[j])
                );
            }
        };
        return helper(0, nums.size() - 1, 0, 0);
    }
};