class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long val = mass;
        for(int &a: asteroids) {
            if(a > val) return false;
            val += a;
        }
        return true;
    }
};