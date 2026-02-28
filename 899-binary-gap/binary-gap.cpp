class Solution {
public:
    int binaryGap(int n) {
        int result=0;
        int s=-1;
        while(n){
            if(n&1){
                if(s!=-1)
                 result=max(result,s);
                s=1;
            }
            else{
                if(s!=-1)
                  s++;
            }
            n=n>>1;
        }
        return result;
    }
};