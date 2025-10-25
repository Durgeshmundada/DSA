class Solution {
public:
    bool reorderedPowerOf2(long long n) {
        unordered_map<long long, long long> um;
        long long y = 0, temp = n;
        while (temp) {
            um[temp % 10]++;
            temp /= 10;
            y++;
        }

        long long lower = 1;
        for (long long i = 1; i < y; i++) lower *= 10;
        long long upper = lower * 10;

        long long x = 1;
        while (x < lower) x *= 2;

        while (x < upper) {
            long long z = x;
            unordered_map<long long, long long> um1 = um;
            while (z != 0 && um1[z % 10] > 0) {
                um1[z % 10]--;
                z /= 10;
            }
            if (z == 0) return true;
            x *= 2;
        }
        return false;
    }
};
