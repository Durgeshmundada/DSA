class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                count--;
            }
            else{
                count++;
            }
            if(count<0){
                res++;
                count=0;
            }
        }
        if(count!=0){
            res+=count;
        }
        return res;
    }
};