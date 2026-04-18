class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>ump;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string dup=strs[i];
            sort(dup.begin(),dup.end());
            ump[dup].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(const auto &u:ump){
            ans.push_back(u.second);
        }
        return ans;
    }
};