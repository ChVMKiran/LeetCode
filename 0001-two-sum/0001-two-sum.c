int* twoSum(int *a,int n,int k,int *r){
    int i,j,*arr=malloc(2*sizeof(int));
    *r=2;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]+a[j]==k){
                arr[0]=i,arr[1]=j;
                break;
            }
        }
    }
    return arr;
}