class Solution {
public:
    bool isMatch(string s, string p) {
        // When pattern is empty, string must also be empty
        if (p.empty()) return s.empty();

        // Does first character match?
        bool firstMatch = !s.empty() && (p[0] == s[0] || p[0] == '.');

        // Case 1: next char in pattern is '*'
        if (p.size() >= 2 && p[1] == '*') {
            // Option 1: treat "x*" as zero occurrences -> skip 2 chars in pattern
            // Option 2: if first matches, consume one char from s and keep pattern same
            return isMatch(s, p.substr(2)) ||
                   (firstMatch && isMatch(s.substr(1), p));
        }
        // Case 2: next char is not '*'
        else {
            // We need first char to match, and then the rest to match
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
