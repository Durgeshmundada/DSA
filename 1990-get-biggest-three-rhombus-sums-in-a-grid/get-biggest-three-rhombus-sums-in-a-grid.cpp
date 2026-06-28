class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        vector<int> sum;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                sum.push_back(grid[i][j]);
                cal1(grid, sum, i, j, i + 1, j - 1, i + 1, j + 1, grid[i][j]);
            }
        }

        sort(sum.begin(), sum.end(), greater<int>());
        sum.erase(unique(sum.begin(), sum.end()), sum.end());

        if (sum.size() > 3)
            return {sum[0], sum[1], sum[2]};

        return sum;
    }

    void cal(vector<vector<int>>& grid, vector<int>& sum,
             int x1, int y1, int x2, int y2, int s) {

        if (x1 >= grid.size() || x2 >= grid.size() ||
            y1 >= grid[0].size() || y2 >= grid[0].size() ||
            x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
            return;

        if (x1 == x2 && y1 == y2) {
            sum.push_back(s + grid[x1][y1]);
            return;
        }

        s += grid[x1][y1] + grid[x2][y2];

        cal(grid, sum, x1 + 1, y1 + 1, x2 + 1, y2 - 1, s);
    }

    void cal1(vector<vector<int>>& grid, vector<int>& sum,
              int x, int y,
              int x1, int y1, int x2, int y2, int s) {

        if (x1 >= grid.size() || x2 >= grid.size() ||
            y1 >= grid[0].size() || y2 >= grid[0].size() ||
            x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
            return;

        int ns = s + grid[x1][y1] + grid[x2][y2];

        cal(grid, sum, x1 + 1, y1 + 1, x2 + 1, y2 - 1, ns);

        cal1(grid, sum, x, y,
             x1 + 1, y1 - 1,
             x2 + 1, y2 + 1,
             ns);
    }
};