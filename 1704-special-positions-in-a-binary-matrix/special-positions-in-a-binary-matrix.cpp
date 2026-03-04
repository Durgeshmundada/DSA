class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat[0].size(),0);
        vector<int> col(mat.size(),0);
        int result=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                row[j]++;
                col[i]++;
            }
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && row[j]==1 && col[i]==1){
                result++;
            }
            }
        }
        
        return result;
    }
};