class Solution {
public:
    bool isValid(string s) {
         stack<char> a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' ||s[i]=='{' || s[i]=='['){
                a.push(s[i]);
            }
            else if(s[i]==')' ||s[i]=='}' || s[i]==']'){
                if(a.empty() ){
                    return false;
                }
                 if ((s[i] == ')' && a.top() != '(') ||
                    (s[i] == '}' && a.top() != '{') ||
                    (s[i] == ']' && a.top() != '[')){
                        return false;
                    }
                a.pop();
            }
        }
        if(a.empty()){
            return true;
        }
        return false;
    
    }
};