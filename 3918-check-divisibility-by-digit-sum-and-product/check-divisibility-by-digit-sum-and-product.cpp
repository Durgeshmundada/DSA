class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int x=n;
        while(x){
            sum+=x%10;
            pro*=x%10;
            x/=10;
        }
        if(n%(sum+pro)==0){
            return true;
        }
        return false;
    }
};