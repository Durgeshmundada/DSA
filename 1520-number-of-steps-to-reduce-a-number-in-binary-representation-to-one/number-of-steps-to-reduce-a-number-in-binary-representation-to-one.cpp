class Solution {
public:
    int numSteps(string s) {
        int result=0;
        int a=1;
        while(s != "1"){
           if(s[s.size()-1]=='1'){
            int check=s.size()-1;
            while(check>=0 && s[check]=='1'){
                s[check]='0';
                check--;
            }
            if(check>=0){
                s[check]='1';
            }
            else{
                s='1'+s;
            }
            result++;
           }
           s.pop_back();
           result++;
        }
        return result;
    }
};