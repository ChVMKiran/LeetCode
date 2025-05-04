class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<long long>dp1(n),dp2(n);
        dp1[0]=energyDrinkA[0];
        dp1[1]=dp1[0]+energyDrinkA[1];
        dp2[0]=energyDrinkB[0];
        dp2[1]=dp2[0]+energyDrinkB[1];
        for(int i=2;i<n;i++){
            dp1[i]=max(dp1[i-1]+energyDrinkA[i],dp2[i-2]+energyDrinkA[i]);
            dp2[i]=max(dp2[i-1]+energyDrinkB[i],dp1[i-2]+energyDrinkB[i]);
        }
        return max(dp1[n-1],dp2[n-1]);
    }
};