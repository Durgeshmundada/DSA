class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Find the range of digits
        int start = i;
        while (i < n && isdigit(s[i])) i++;
        int h = i;

        if (h == start) return 0; // no digits found

        // 4. Convert digits to number
        long long sum = 0;
        for (int k = start; k < h; k++) {
            int digit = s[k] - '0';
            sum = sum * 10 + digit;

            // 5. Clamp on overflow
            if (sign == 1 && sum > INT_MAX) return INT_MAX;
            if (sign == -1 && sum > (long long)INT_MAX + 1) return INT_MIN;
        }

        return (int)(sum * sign);
    }
};
