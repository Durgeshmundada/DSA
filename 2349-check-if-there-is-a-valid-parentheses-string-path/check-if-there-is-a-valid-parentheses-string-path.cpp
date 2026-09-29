class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n + 1, -1))
        );

        return check(grid, 0, 0, 0, dp);
    }

    bool check(vector<vector<char>>& grid, int x, int y, int count,
               vector<vector<vector<int>>>& dp) {

        if (x >= grid.size() || y >= grid[0].size())
            return false;

        if (grid[x][y] == '(')
            count++;
        else
            count--;

        if (count < 0)
            return false;

        if (dp[x][y][count] != -1)
            return dp[x][y][count];

        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            if (count == 0)
                return true;
            else
                return false;
        }

        return dp[x][y][count] =
            check(grid, x + 1, y, count, dp) ||
            check(grid, x, y + 1, count, dp);
    }
};