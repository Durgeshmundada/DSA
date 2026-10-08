class Solution {
public:
    int scoreOfParentheses(string s) {
        int idx=0;
        return check(s,idx);
    }
    int check(string s, int& idx){
         int ans=0;
         while (idx < s.size() && s[idx] != ')') {
                idx++;
                int x = check(s, idx);

                if (s[idx - 1] == '(') {
                    ans += 1;
                } else {
                    ans += 2 * x;
                }
                idx++;
    }
    return ans;
    }
};