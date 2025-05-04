class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxi=0;
        for (auto i:intervals){
            maxi=max(maxi,i[1]);
        }
        vector<int>data(maxi+2,0);
        for(auto i:intervals){
            data[i[0]]++;
            data[i[1]+1]--;
        }
        int ans=data[0];
        for(int i=1;i<maxi+2;i++){
            data[i]+=data[i-1];
            ans=max(data[i],ans);
        }
        return ans;
    }
};