class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            for(int j=0;j<(image[i].size()+1)/2;j++){
               swap(image[i][j],image[i][image[i].size()-1-j]);
               image[i][j]=!image[i][j];
               if(j != image[i].size() - 1 - j){
               image[i][image[i].size()-1-j]=!image[i][image[i].size()-1-j];
               }
            }
           
        }
  return image;
    }
};