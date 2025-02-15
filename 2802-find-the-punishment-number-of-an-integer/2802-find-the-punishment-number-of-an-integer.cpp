class Solution {
public:
    bool isPunished(string str,int target){
        if(str==""&&target==0)return true;
        if(target<0)return false;
        int n=str.size();
        for(int i=0;i<n;i++){
            if(isPunished(str.substr(i+1),target-stoi(str.substr(0,i+1))))return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            if(isPunished(to_string(sq),i))ans+=sq;
        }
        return ans;
    }
};