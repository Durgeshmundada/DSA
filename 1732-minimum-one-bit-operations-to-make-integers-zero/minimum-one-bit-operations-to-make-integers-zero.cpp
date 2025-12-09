class Solution {
public:
    int minimumOneBitOperations(int n) {
        int count=0;
        int check=0;
        long long s=1;
        while(n){
            if(n%2!=0){
             count = (2 * s - 1) - count;
            }
            s=s*2;
            n=n>>1;
        }   
        return count;
    }
};