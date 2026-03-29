class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) return true;

        string t = s1;

        // swap (0,2)
        swap(t[0], t[2]);
        if (t == s2) return true;

        // swap (1,3) on original
        t = s1;
        swap(t[1], t[3]);
        if (t == s2) return true;

        // swap both
        t = s1;
        swap(t[0], t[2]);
        swap(t[1], t[3]);
        if (t == s2) return true;

        return false;
    }
};