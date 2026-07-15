class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int ever=0;
        int odd=0;
        for(int i=1;i<=n*2;i++){
            if(i%2!=0) odd+=i;
            else ever+=i;
        }
        return __gcd(ever,odd);
    }
};