class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

vector<vector<int>> result(n - k + 1, vector<int>(m - k + 1));
        vector<int>r1;
        for(int i=0;i<=grid.size()-k;i++){
            for(int j=0;j<=grid[0].size()-k;j++){
               for(int x=i;x<i+k;x++ ){
                for(int y=j;y<j+k;y++){
                    r1.push_back(grid[x][y]);
                }
               }
               sort(r1.begin(),r1.end());
               int r2=INT_MAX;
               for(int z=1;z<r1.size();z++){
                if(r1[z]!=r1[z-1]){
                    r2=min(r2,abs(r1[z]-r1[z-1]));
                }
               }
               if(r2 == INT_MAX) r2 = 0;
               result[i][j]=r2;
               r1.clear();
            }
        }
        return result;
    }
};