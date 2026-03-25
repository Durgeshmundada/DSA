class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }

        long long top = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                top += grid[i][j];
            }
            if(top == total - top) return true;
        }


        long long left = 0;
        for(int j = 0; j < m - 1; j++) {
            for(int i = 0; i < n; i++) {
                left += grid[i][j];
            }
            if(left == total - left) return true;
        }

        return false;
    }
};