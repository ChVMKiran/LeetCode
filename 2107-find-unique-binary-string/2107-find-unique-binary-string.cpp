class Solution {
public:
    int n;
    bool solve(vector<string>&nums,string&ans,unordered_set<string>&ust){
        if(ans.size()==n){
            if(ust.find(ans)!=ust.end())return false;
            return true;
        }
        ans+="0";
        if(solve(nums,ans,ust))return true;
        ans.pop_back();
        ans+="1";
        if(solve(nums,ans,ust))return true;
        ans.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        string ans;
        unordered_set<string>ust(nums.begin(),nums.end());
        solve(nums,ans,ust);
        return ans;
    }
};