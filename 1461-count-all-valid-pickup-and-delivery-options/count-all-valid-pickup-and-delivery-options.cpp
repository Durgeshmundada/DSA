class Solution {
public:
int MOD=1000000007;
    int countOrders(int n) {
        long long result=1;
        for(int i=1;i<=n;i++){
            result = (result * i) % MOD;
            result = (result * (2LL * i - 1)) % MOD;
        }
        return result;
    }
};