class Solution {
public:
    int ind=0;
    string res;
    bool solve(string& ans, int n,int k){
        if(ans.size()==n){
            ind++;
            if(ind==k){
                res=ans;
                return true;
            }
            return false;
        }
        if(ans.empty()||ans.back()!='a'){
            ans+="a";
            if(solve(ans,n,k))return true;
            ans.pop_back();
        }
        if(ans.empty()||ans.back()!='b'){
            ans+="b";
            if(solve(ans,n,k))return true;
            ans.pop_back();
        }
        if(ans.empty()||ans.back()!='c'){
            ans+="c";
            if(solve(ans,n,k))return true;
            ans.pop_back();
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string ans;
        solve(ans,n,k);
        return res;
    }
};