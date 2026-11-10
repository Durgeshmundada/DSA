class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return check(0, n, costs, dp);
    }

    int check(int x, int n, vector<int>& costs, vector<int>& dp) {

        if (x == n) return 0;

        if (dp[x] != -1) return dp[x];

        int res = INT_MAX;

        for (int jump = 1; jump <= 3; jump++) {

            int next = x + jump;

            if (next <= n) {
                int cost = costs[next - 1] + jump * jump;

                res = min(res, cost + check(next, n, costs, dp));
            }
        }

        return dp[x] = res;
    }
};