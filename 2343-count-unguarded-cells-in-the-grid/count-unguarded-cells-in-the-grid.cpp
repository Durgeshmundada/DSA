class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i=0;i<guards.size();i++){
            matrix[guards[i][0]][guards[i][1]]=1;
        }
         for(int i=0;i<walls.size();i++){
            matrix[walls[i][0]][walls[i][1]]=2;
        }
        int result=0;
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            for(int j=x-1;j>=0;j--){
                if (matrix[j][y] == 1 || matrix[j][y] == 2) {
                    break;
                } else if (matrix[j][y] == 0) {
                    matrix[j][y] = 3;
                   result++;
                }
            }
            for(int j=x+1;j<m;j++){
                if (matrix[j][y] == 1 || matrix[j][y] == 2) {
                    break;
                } else if (matrix[j][y] == 0) {
                    matrix[j][y] = 3;
                    result++;
                }
            }
            for(int j=y-1;j>=0;j--){
                if (matrix[x][j] == 1 || matrix[x][j] == 2) {
                    break;
                } else if (matrix[x][j] == 0) {
                    matrix[x][j] = 3;
                   result++;
                }
            }
            for(int j=y+1;j<n;j++){
                if (matrix[x][j] == 1 || matrix[x][j] == 2) {
                    break;
                } else if (matrix[x][j] == 0) {
                    matrix[x][j] = 3;
                   result++;
                }
            }
        }
        

         int totalBlocked = guards.size() + walls.size();
        return (m * n) - result - totalBlocked;

    }
};