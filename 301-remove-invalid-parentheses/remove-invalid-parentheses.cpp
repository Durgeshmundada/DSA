class Solution {
public:
    set<string> ans;
    int lremove, rremove;

    void solve(string &s, int idx, string curr, int l, int r, int balance) {

        if (idx == s.size()) {
            if (l == 0 && r == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        // TAKE
        if (s[idx] != '(' && s[idx] != ')') {
            solve(s, idx + 1, curr + s[idx], l, r, balance);
        }
        else if (s[idx] == '(') {
            solve(s, idx + 1, curr + s[idx], l, r, balance + 1);
        }
        else {
            if (balance > 0) {
                solve(s, idx + 1, curr + s[idx], l, r, balance - 1);
            }
        }

        // NOT TAKE
        if (s[idx] == '(' && l > 0) {
            solve(s, idx + 1, curr, l - 1, r, balance);
        }

        if (s[idx] == ')' && r > 0) {
            solve(s, idx + 1, curr, l, r - 1, balance);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        lremove = 0;
        rremove = 0;

        // Find minimum '(' and ')' removals
        for (char c : s) {
            if (c == '(') {
                lremove++;
            }
            else if (c == ')') {
                if (lremove > 0)
                    lremove--;
                else
                    rremove++;
            }
        }

        solve(s, 0, "", lremove, rremove, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};