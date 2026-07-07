class Solution {
public:
    long long sumAndMultiply(int n) {
        long long  sum=0;
        long long  carr=1;
        long long x=0;
        while(n>0){
            cout<<sum<<" "<<carr<<" "<<x<<" "<<n<<endl;
            if(n%10!=0){
                x=(carr*(n%10))+x;
                carr=carr*10;
                sum+=n%10;
            }
            n=n/10;
        }
        return x*sum;
    }
};