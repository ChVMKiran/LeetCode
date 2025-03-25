class Solution {
private:
    static bool horizontal(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    static bool vertical(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), horizontal);
        int count = 0, m = rectangles.size(), prevEnd = rectangles[0][2];
        for(int i = 1; i < m; i++) {
            if(prevEnd <= rectangles[i][0]) count++;
            prevEnd = max(rectangles[i][2], prevEnd);
            if(count == 2) return true;
        }
        sort(rectangles.begin(), rectangles.end(), vertical);
        count = 0, prevEnd = rectangles[0][3];
        for(int i = 1; i < m; i++) {
            if(prevEnd <= rectangles[i][1]) count++;
            prevEnd = max(rectangles[i][3], prevEnd);
            if(count == 2) return true;
        }
        return false;
    }
};