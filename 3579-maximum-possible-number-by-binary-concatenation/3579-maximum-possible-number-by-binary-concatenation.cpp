class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        string a = bitset<8>(nums[0]).to_string();
        string b = bitset<8>(nums[1]).to_string();
        string c = bitset<8>(nums[2]).to_string();
        a.erase(0, a.find('1'));
        b.erase(0, b.find('1'));
        c.erase(0, c.find('1'));
        string ans = max({a+b+c, a+c+b, b+c+a, b+a+c, c+a+b, c+b+a});
        return stoi(ans, 0, 2);
    }
};