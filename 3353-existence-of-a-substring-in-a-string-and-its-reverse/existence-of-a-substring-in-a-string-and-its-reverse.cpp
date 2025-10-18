class Solution {
public:
    bool isSubstringPresent(string s) {
       string s1=s;
        reverse(s1.begin(),s1.end());
        for(int i=0;i<s.size()-1;i++){
            string x="";
            x=x+s1[i]+s1[i+1];
            if(s.find(x)!= string::npos){
                return true;
            }
        }
        return false;
    }
};