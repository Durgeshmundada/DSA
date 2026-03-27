class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        if(k%mat[0].size()==0) return true;
        k=k%mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i%2==0){
                  if(mat[i][(j+k)%m]!=mat[i][j]) return false;
                }
                else{
                    if(mat[i][(j-k+m)%m]!=mat[i][j]) return false;
                }
            }
        }
        return true;

    }
};