class Solution {
private:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int crt = round(cbrt(nums[i])); //crt->cube root
            if(crt * crt * crt == nums[i] && isPrime(crt)) {
                ans += (1 + crt + crt * crt + crt * crt * crt);
                continue;
            }
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    int a = j, b = nums[i] / j;
                    if (a != b && isPrime(a) && isPrime(b)) {
                        ans += (1 + a + b + nums[i]);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};