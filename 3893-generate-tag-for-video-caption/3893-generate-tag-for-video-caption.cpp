class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        int up = 0, n = caption.size();
        if(caption[0] != ' ') res.push_back(tolower(caption[0]));
        for(int i = 1; i < n; i++) {
            if(caption[i] == ' ') {
                if(res.size() > 1) up = 1;
            }
            else {
                if(up) {
                    res += toupper(caption[i]);
                    up = 0;
                }
                else {
                    res += tolower(caption[i]);
                }
                if(res.size() == 100) break;
            }
        }
        return res;
    }
};