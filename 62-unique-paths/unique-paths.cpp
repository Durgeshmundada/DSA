class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(0,0,m-1,n-1,dp);
    }
    int check(int x,int y,int m,int n,vector<vector<int>>&dp){
        if(x==m && y==n) return 1;
        if(x>m || y>n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=check(x+1,y,m,n,dp)+check(x,y+1,m,n,dp);
    }
};