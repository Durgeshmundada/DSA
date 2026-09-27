class Solution {
public:

    int i = 0;

    string reverseParentheses(string s) {

        stack<char> st;

        while(i < s.size()) {

            if(s[i] == '(') {

                i++;

                stack<char> ss = check(s);

                while(!ss.empty()) {
                    st.push(ss.top());
                    ss.pop();
                }

                i++;   
            }
            else {

                st.push(s[i]);
                i++;
            }
        }

        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }


    stack<char> check(string s) {

        stack<char> st;

        while(i < s.size() && s[i] != ')') {

            if(s[i] == '(') {

                i++;   

                stack<char> ss = check(s);

                while(!ss.empty()) {
                    st.push(ss.top());
                    ss.pop();
                }

                i++;   
            }
            else {

                st.push(s[i]);
                i++;
            }
        }

        return st;
    }
};