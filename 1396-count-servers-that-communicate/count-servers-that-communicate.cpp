class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>x(m,0);
        vector<int>y(n,0);
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x[i]++;
                    y[j]++;
                    
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (x[i]>1 || y[j]>1)){
                    res++;
                }
            }
        }
        return res;
    }
};