class Solution {
public:
    bool judgeSquareSum(int c) {
        long long x=sqrt(c);
        long long y=0;
        while(x>=y){
            if(x*x+y*y==c)return true;
            if(x*x+y*y>c){
                x--;
            }
            else y++;
        }
        return false;
    }
};