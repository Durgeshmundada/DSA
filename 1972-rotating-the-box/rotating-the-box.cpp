class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> result(boxGrid[0].size(), vector<char>(boxGrid.size()));
        for(int i=boxGrid.size()-1;i>=0;i--){
            int x=boxGrid[0].size()-1;
            for(int j=boxGrid[0].size()-1;j>=0;j--){
                if(boxGrid[i][j]=='.'){
                    result[j][boxGrid.size()-1-i]='.';
                }
                else if(boxGrid[i][j]=='*'){
                    result[j][boxGrid.size()-1-i]='*';
                    x=j-1;
                }
                else{
                    result[j][boxGrid.size()-1-i]='.';
                    result[x][boxGrid.size()-1-i]='#';
                    x--;  
                }
            }
        }
        return result;
    }
};