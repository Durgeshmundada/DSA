class Solution {
public:
    string countAndSay(int n) {
       if(n==1){
            return "1";
        }
        string s=countAndSay(n-1);
        string b="";
    for(int i=0;i<s.size();i++){
        int count=0;
        int x=i;
        while(s[x]==s[i]){
            count++;
            i++;
        }
       b+=to_string(count)+s[x];
       i--;
      
    }
     return b;
    } 
        
};