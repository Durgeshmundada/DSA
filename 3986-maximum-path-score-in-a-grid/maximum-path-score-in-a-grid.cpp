class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(
            grid.size(),
            vector<vector<int>>(grid[0].size(), vector<int>(k + 1, -2))
        );

        return maxp(grid, k, dp, 0, 0, 0);
    }

    int maxp(vector<vector<int>>& grid, int k,
             vector<vector<vector<int>>>& dp,
             int cost, int idx1, int idx2) {

        if (grid[idx1][idx2] != 0)
            cost++;

        if (cost > k)
            return -1;

        if (dp[idx1][idx2][cost] != -2)
            return dp[idx1][idx2][cost];

        if (idx1 == grid.size() - 1 && idx2 == grid[0].size() - 1)
            return grid[idx1][idx2];

        int down = -1;
        int right = -1;

        if (idx1 < grid.size() - 1)
            down = maxp(grid, k, dp, cost, idx1 + 1, idx2);

        if (idx2 < grid[0].size() - 1)
            right = maxp(grid, k, dp, cost, idx1, idx2 + 1);

        int ans = max(down, right);

        if (ans == -1)
            return dp[idx1][idx2][cost] = -1;

        return dp[idx1][idx2][cost] = grid[idx1][idx2] + ans;
    }
};