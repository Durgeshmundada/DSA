class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++){
             bool flag=false;
             int a=0;
            for(int j=i;j<grid.size();j++){
               
                for(int k=i+1;k<grid[0].size();k++){
                    if(grid[j][k]!=0){
                        flag=true;
                        break;
                    }
                    flag=false;
                }
                if(!flag){
                    a=j;
                    break;
                }
            }
            if(flag){
                    return -1;
                }
                result=result+(a-i);
                for(int j=a;j>i;j--){
                    swap(grid[j],grid[j-1]);
                }
        }
        return result;
    }
};