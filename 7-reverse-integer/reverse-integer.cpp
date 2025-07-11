class Solution {
public:
    int reverse(int n) {
        long long rev = 0;  // Use long long to detect overflow

    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    // Check for overflow
    if (rev < INT_MIN || rev > INT_MAX)
        return 0;

    return (int)rev;

        
    }
};