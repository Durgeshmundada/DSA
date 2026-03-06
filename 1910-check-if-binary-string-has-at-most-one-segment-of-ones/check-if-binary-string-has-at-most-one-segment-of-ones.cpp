class Solution {
public:
    bool checkOnesSegment(string s) {
        bool result=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' ){
                if(result){
                    return false;
                }
                else{
                    while(i<s.size() && s[i]=='1' ){
                        i++;
                    }
                    result=true;
                }
            }
        }
        return result;
    }
};