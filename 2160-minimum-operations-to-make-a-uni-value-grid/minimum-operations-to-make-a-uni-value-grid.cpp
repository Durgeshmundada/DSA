class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> result(grid.size()*grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                result[i*grid[0].size()+j]=grid[i][j];
            }
        }
        sort(result.begin(),result.end());
        int mid=result.size()/2;
        int ans=0;
        for(int i=0;i<result.size();i++){
            if(abs(result[i]-result[mid])%x!=0) return -1;
            ans+=abs(result[i]-result[mid])/x;
        }
        return ans;
    }
};