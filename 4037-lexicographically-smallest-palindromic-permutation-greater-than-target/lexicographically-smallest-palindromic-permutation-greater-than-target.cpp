class Solution {
public:

    char middle = '#';

    string lexPalindromicPermutation(string s, string target) {

        unordered_map<char, int> um;

        for (char c : s)
            um[c]++;

        bool flag = false;

        for (auto &x : um) {

            if (x.second % 2 != 0) {

                if (flag)
                    return "";

                flag = true;
                middle = x.first;
            }

            x.second /= 2;
        }

        string targetLeft = target.substr(0, s.size() / 2);

        // Check if targetLeft can be formed
        unordered_map<char, int> temp = um;
        bool canMake = true;

        for (char c : targetLeft) {

            if (temp[c] == 0) {
                canMake = false;
                break;
            }

            temp[c]--;
        }

        // First try targetLeft itself
        if (canMake) {

            string right = targetLeft;
            reverse(right.begin(), right.end());

            string result;

            if (s.size() % 2 == 1)
                result = targetLeft + string(1, middle) + right;
            else
                result = targetLeft + right;

            if (result > target)
                return result;
        }

        // Now find a strictly greater left half
        string left = check(um, targetLeft, "");

        if (left == "")
            return "";

        string right = left;
        reverse(right.begin(), right.end());

        if (s.size() % 2 == 1)
            return left + string(1, middle) + right;

        return left + right;
    }


    string check(unordered_map<char, int>& um,
                 string target,
                 string ans) {

        if (ans.size() == target.size()) {

            if (ans > target)
                return ans;

            return "";
        }

        int pos = ans.size();
        char tc = target[pos];

        // Keep same character
        if (um[tc] > 0) {

            um[tc]--;
            ans += tc;

            string res = check(um, target, ans);

            if (res != "")
                return res;

            ans.pop_back();
            um[tc]++;
        }

        // Take smallest character greater than target character
        for (char c = tc + 1; c <= 'z'; c++) {

            if (um[c] > 0) {

                ans += c;
                um[c]--;

                // Fill remaining characters minimally
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