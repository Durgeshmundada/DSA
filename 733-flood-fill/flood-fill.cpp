class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        int n=grid[sr][sc];
        dfs(grid,sr,sc,dp,color,n);
        return grid;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,int color,int n){
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] != n || dp[i][j] == 1) {
        return;
    }
    dp[i][j]=1;
    grid[i][j]=color;
    dfs(grid,i-1,j,dp,color,n);
    dfs(grid,i,j-1,dp,color,n);
    dfs(grid,i+1,j,dp,color,n);
    dfs(grid,i,j+1,dp,color,n);
    return;
}
};