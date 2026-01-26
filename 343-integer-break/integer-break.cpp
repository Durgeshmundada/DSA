class Solution {
public:
vector<int> dp;
Solution() : dp(59, -1) {}

    int integerBreak(int n) {
        if(n<2){
            return 1;
        }
        if (dp[n] != -1) return dp[n];
        int ma=0;
        for(int i=1;i<n;i++){
            ma=max(ma,i*max(n-i,integerBreak(n-i)));
        }
       return dp[n]=ma;
    }
    
};