class Solution {
public:
    bool hasSameDigits(string s) {
        string k="";
        while(s.size()>2){
           for(int i=0;i<s.size()-1;i++){
            int x = s[i] - '0';
            int y = s[i + 1] - '0';
            k=k+to_string((x+y)%10);
           }
           s=k;
           k="";
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
    }
};