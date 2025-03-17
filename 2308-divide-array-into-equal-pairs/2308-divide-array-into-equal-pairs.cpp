class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, bool> ump;
        for(const int &i :nums) {
            if(ump.find(i) != ump.end()) ump[i] = !ump[i];
            else ump[i] = true;
        }
        for(auto &a :ump) {
            if(a.second) return false;
        }
        return true;
    }
};