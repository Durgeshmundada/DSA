class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long n=0;
        int count =1;
        for(int i=1;i<=k;i++){    
           n=((n*10)+1)%k;
           if(n==0){
            return i;
           }
        }
        return -1;
    }
};