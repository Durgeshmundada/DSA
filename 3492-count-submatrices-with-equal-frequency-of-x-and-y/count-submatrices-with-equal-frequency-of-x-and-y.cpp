class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

       
        vector<vector<vector<int>>> result(n+1, vector<vector<int>>(m+1, vector<int>(2, 0)));

       
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                
                result[i][j][0] = result[i-1][j][0] + result[i][j-1][0] - result[i-1][j-1][0];
                result[i][j][1] = result[i-1][j][1] + result[i][j-1][1] - result[i-1][j-1][1];

                if(grid[i-1][j-1] == 'X'){
                    result[i][j][0]++;
                }
                else if(grid[i-1][j-1] == 'Y'){
                    result[i][j][1]++;
                }
            }
        }
        int count = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(result[i][j][0] > 0 && result[i][j][0] == result[i][j][1]){
                    count++;
                }
            }
        }

        return count;
    }
};