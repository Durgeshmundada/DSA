class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int count=0;
        int idx=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                if(count==0){
                idx=i;
            }
                count++;
            }
            else{
                count--;
                if(count==0){
                res += s.substr(idx+1, i - idx-1);
            }
            }
        }
        return res;
    }
};