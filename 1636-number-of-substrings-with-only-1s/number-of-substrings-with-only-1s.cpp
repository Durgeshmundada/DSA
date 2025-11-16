class Solution {
public:
    int numSub(string s) {
        long long MOD = 1e9 + 7;
        long long l = 0;
        long long count = 0;

        for (char c : s) {
            if (c == '1') {
                l++;
            } else {
                count = (count + (l * (l + 1) / 2) % MOD) % MOD;
                l = 0;
            }
        }

        // Add last segment
        if (l > 0) {
            count = (count + (l * (l + 1) / 2) % MOD) % MOD;
        }

        return count % MOD;
    }
};
