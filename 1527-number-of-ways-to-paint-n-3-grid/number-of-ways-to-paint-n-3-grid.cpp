class Solution {
public:
    int numOfWays(int n) {
        const int mod= 1000000007;
        long long same=6;
        long long diff=6;
        for(int i=2;i<=n;i++){
            long long nsame=(3*same+2*diff)%mod;
            long long ndiff=(2*same+2*diff)%mod;
            same=nsame;
            diff=ndiff;
        }
        return (same+diff)%mod;
    }
    
};