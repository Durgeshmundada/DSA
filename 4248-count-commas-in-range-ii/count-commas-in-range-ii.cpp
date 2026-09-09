class Solution {
public:
    long long countCommas(long long n) {
        int s = 0;
        long long s1 = n;

        while (s1) {
            s++;
            s1 /= 10;
        }

        if (s <= 3) return 0;
        long long ans = 0;
        long long p = 1000;

        while (p <= n) {
           
            ans += n - p + 1;

            p *= 1000;
            
        }

        return ans;
    }
};