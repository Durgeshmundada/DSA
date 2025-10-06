#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir = "";
        string result = "";

       
        if (path[0] != '/') path.insert(0, "/");
        if (path.back() != '/') path.push_back('/');

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (dir == "" || dir == ".") {
    
                } 
                else if (dir == "..") {
                    if (!st.empty()) st.pop();
                } 
                else {
                    st.push(dir);
                }
                dir = ""; 
            } 
            else {
                dir += path[i];
            }
        }

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        if (result == "") result = "/";
        return result;
    }
};
