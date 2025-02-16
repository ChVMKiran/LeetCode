class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>used(n+1,false);
        solve(res,used,0,n);
        return res;
    }
    bool solve(vector<int>&res,vector<bool>&used,int ind,int n){
        if(ind==2*n-1)return true;
        if(res[ind])return solve(res,used,ind+1,n);
        for(int i=n;i>=1;i--){
            if(used[i])continue;
            used[i]=true;
            res[ind]=i;
            if(i==1){
                if(solve(res,used,ind+1,n))return true;
            }
            else if(ind+i<2*n-1&&res[ind+i]==0){
                res[ind+i]=i;
                if(solve(res,used,ind+1,n))return true;
                res[ind+i]=0;
            }
            res[ind]=0;
            used[i]=false;
        }
        return false;
    }
};