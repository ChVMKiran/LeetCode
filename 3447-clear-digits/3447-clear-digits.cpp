class Solution {
public:
    string clearDigits(string s) {
        string res;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                res.pop_back();
            }
            else res+=s[i];
        }
        return res;
    }
};