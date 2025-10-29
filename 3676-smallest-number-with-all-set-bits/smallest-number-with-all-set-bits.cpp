class Solution {
public:
    int smallestNumber(int n) {
        if(n<2){
            return 1;
        }
        int i=1;
        while(i<=n){
            i=i<<1;
        }
        return i-1;
    }
};