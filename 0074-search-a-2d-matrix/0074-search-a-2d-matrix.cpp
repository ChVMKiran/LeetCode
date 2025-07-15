class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),low=0,high=m-1,row=-1;
        if(m>1){
            while(low<=high){
                int mid=(low+high)/2;
                if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                    row=mid;
                    break;
                }
                else if(matrix[mid][n-1]<target)low=mid+1;
                else high=mid-1;
            }
            if(row==-1)return false;
        }
        else row=0;
        cout<<row<<n;
        low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};