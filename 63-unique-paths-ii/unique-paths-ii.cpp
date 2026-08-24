class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(0,0,m-1,n-1,dp,obstacleGrid);
    }
    int check(int x,int y,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& o){
        if(x>m || y>n) return 0;
        if(o[x][y]==1) return dp[x][y]=0;
        
        if(x==m && y==n) return 1;
        
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=check(x+1,y,m,n,dp,o)+check(x,y+1,m,n,dp,o);
    }
};