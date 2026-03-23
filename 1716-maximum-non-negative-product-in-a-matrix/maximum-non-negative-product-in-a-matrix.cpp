class Solution {
public:
    int m, n;
    const int mod = 1e9 + 7;

    vector<vector<pair<long long,long long>>> dp;
    int maxProductPath(vector<vector<int>>& grid) {
         m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MIN}));

        auto res = solve(grid, 0, 0);

        if(res.first < 0) return -1;
        return res.first % mod;
    }

    pair<long long ,long long> solve(vector<vector<int>>& grid, int start, int end) {

        if(start == m-1 && end == n-1){
            return {grid[start][end],grid[start][end]};
        }
        if(dp[start][end].first != LLONG_MIN) return dp[start][end];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;
        if(end+1<n){
            auto right = solve(grid, start, end+1);
            long long a=right.first*grid[start][end];
            long long b=right.second*grid[start][end];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }
        if(start+1<m){
            auto down = solve(grid, start+1, end);
            long long a=down.first*grid[start][end];
            long long b=down.second*grid[start][end];
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }
        return dp[start][end] = {maxi, mini};
    }
};