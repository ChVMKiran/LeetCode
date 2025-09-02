class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = 0; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if(i == j || x1 > x2 || y1 < y2) continue;
                // checking whether (x2,y2) is in upper left for (x1,y1) or not
                bool flag = true;
                for(int k = 0; k < n; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if(k != i && k != j && x1 <= x3 && x3 <= x2 && y2 <= y3 && y3 <= y1) {
                        // checking if any point(x3,y3) is inside the area of 
                        // rectangle formed by points(x1,y1) and (x2,y2)
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};