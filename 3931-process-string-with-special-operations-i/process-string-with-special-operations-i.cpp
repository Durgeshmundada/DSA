class Solution {
public:
    string processStr(string s) {
      string result="";
      for(int i=0;i<s.size();i++){
        if(s[i]=='*'){
            if(result.size()!=0)
               result.erase(result.begin()+result.size()-1, result.end());
        }
        else if(s[i]=='#'){
            result+=result;
        }
        else if(s[i]=='%'){
            reverse(result.begin(),result.end());
        }
        else{
            result+=s[i];
        }
      } 
      return result; 
    }
};