class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res, n=nums.size();
        sort(nums.begin(),nums.end());
        res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            if(i&&nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                int curr=nums[i]+nums[j]+nums[k];
                if(abs(target-res)>abs(curr-target))res=curr;
               if(curr>target){
                    k--;
                }
                else if(curr<target){
                    j++;
                }
                else{
                    return target;
                }
            }
        }
        return res;
    }
};