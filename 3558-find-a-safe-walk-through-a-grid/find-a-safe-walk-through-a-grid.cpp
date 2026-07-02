class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return sol(grid, health, dp, 0, 0);
    }

    bool sol(vector<vector<int>>& grid, int health, vector<vector<int>>& dp, int i, int j) {

        if (grid[i][j]) health--;

        if (health <= 0) return false;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return true;

        if (dp[i][j] >= health)
            return false;

        dp[i][j] = health;

        if (j + 1 < grid[0].size() && sol(grid, health, dp, i, j + 1))
            return true;

        if (j > 0 && sol(grid, health, dp, i, j - 1))
            return true;

        if (i > 0 && sol(grid, health, dp, i - 1, j))
            return true;

        if (i + 1 < grid.size() && sol(grid, health, dp, i + 1, j))
            return true;

        return false;
    }
};