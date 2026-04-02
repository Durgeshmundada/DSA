class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        // Base case
        for (int k = 0; k < 3; k++) {
            if (coins[n-1][m-1] < 0 && k > 0)
                dp[n-1][m-1][k] = 0;
            else
                dp[n-1][m-1][k] = coins[n-1][m-1];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n-1 && j == m-1) continue;

                for (int k = 0; k < 3; k++) {
                    int best = INT_MIN;

                    if (i + 1 < n) best = max(best, dp[i+1][j][k]);
                    if (j + 1 < m) best = max(best, dp[i][j+1][k]);

                    if (best != INT_MIN)
                        best += coins[i][j];

                    if (coins[i][j] < 0 && k > 0) {
                        int skip = INT_MIN;
                        if (i + 1 < n) skip = max(skip, dp[i+1][j][k-1]);
                        if (j + 1 < m) skip = max(skip, dp[i][j+1][k-1]);

                        best = max(best, skip);
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[0][0][2];
    }
};