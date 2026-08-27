class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int> um;

        for (char c : s) {
            um[c]++;
        }

        return check(um, target, "");
    }

    string check(unordered_map<char, int>& um,string target,string ans) {

        if (ans.size() == target.size()) {
            if (ans > target)
                return ans;
            return "";
        }

        int pos = ans.size();
        char tc = target[pos];

        if (um[tc] > 0) {

            um[tc]--;
            ans += tc;

            string res = check(um, target, ans);

            if (res.size() == target.size())
                return res;
            ans.pop_back();
            um[tc]++;
        }

        for (char c = tc + 1; c <= 'z'; c++) {

            if (um[c] > 0) {

                ans += c;
                um[c]--;

               
                for (char x = 'a'; x <= 'z'; x++) {
                    while (um[x] > 0) {
                        ans += x;
                        um[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};