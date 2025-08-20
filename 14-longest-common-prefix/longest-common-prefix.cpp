class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string s1 = strs.back(); strs.pop_back();
        string s2 = strs.back(); strs.pop_back();
        
        string prefix = "";
        int n = min(s1.size(), s2.size());
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) prefix += s1[i];
            else break;
        }

        strs.push_back(prefix);
        return longestCommonPrefix(strs);
    }
};