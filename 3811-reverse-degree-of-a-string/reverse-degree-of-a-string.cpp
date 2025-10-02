class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            int a=123-(int)s[i];
            result=result+(a*(i+1));
        }
        return result;
    }
};