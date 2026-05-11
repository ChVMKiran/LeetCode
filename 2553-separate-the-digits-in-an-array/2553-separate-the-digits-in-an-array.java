class Solution {
    public int[] separateDigits(int[] nums) {
        int n = 0;
        for(int num: nums) {
            n += Math.log10(num) + 1;
        }
        int[] arr = new int[n];
        for(int i = nums.length - 1, j = n - 1; i >= 0; i--) {
            int k = nums[i];
            while(k > 0) {
                arr[j--] = k % 10;
                k /= 10;
            }
        }
        return arr;
    }
}