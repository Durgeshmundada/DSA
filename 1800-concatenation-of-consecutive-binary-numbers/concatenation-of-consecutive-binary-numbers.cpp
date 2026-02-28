class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long result = 0;
        long long sq = 2;  

        for (int i = 1; i <= n; i++) {
            
            if ((i & (i - 1)) == 0 && i != 1) {
                sq = (sq * 2) % mod;
            }

            result = (result * sq) % mod;
            result = (result + i) % mod;
        }
        return result;
    }
};