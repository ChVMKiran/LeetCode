class Solution {
private:
    bool solve(string &ans,string &pattern,bool freq[]){
        if(ans.size()==pattern.size()+1)return true;
        // cout<<1;
        for(int i=1;i<10;i++){
            if(freq[i])continue;
            if(ans.empty()){
                ans.push_back(i+'0');
                freq[i]=true;
                if(solve(ans,pattern,freq))return true;
                freq[i]=false;
                ans.pop_back();
                continue;
            }
            if(pattern[ans.size()-1]=='I'&&ans.back()-'0'<i){
                ans.push_back(i+'0');
                freq[i]=true;
                if(solve(ans,pattern,freq))return true;
                freq[i]=false;
                ans.pop_back();
            }
            else if(pattern[ans.size()-1]=='D'&&ans.back()-'0'>i){
                ans.push_back(i+'0');
                freq[i]=true;
                if(solve(ans,pattern,freq))return true;
                freq[i]=false;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        string ans;
        bool freq[10]={0};
        solve(ans,pattern,freq);
        return ans;
    }
};