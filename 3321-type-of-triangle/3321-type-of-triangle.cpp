class Solution {
public:
    string triangleType(vector<int>& nums){
            int i=nums[0],j=nums[1],k=nums[2];
                if(i==j&&j==k)return "equilateral";
                    else if((i==j||j==k||k==i)&&i+j>k&&j+k>i&&k+i>j)return "isosceles";
                        else if(i+j>k&&j+k>i&&k+i>j)return "scalene";
                            return "none";
    }
};