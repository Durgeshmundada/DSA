class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int min=INT_MAX;
        long long neg=0;
        long long sum=0;
       
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                
                  if(matrix[i][j]<0){
                    neg++;
                  }
                  if(abs(min)>abs(matrix[i][j])){
                        min=abs(matrix[i][j]);
                    }
                  
                  sum+=abs(matrix[i][j]);
                }
            }
            cout<<sum<<" "<<neg<<" "<< min;
        if(neg%2!=0){
            sum-=2*min;
            }
            return sum;
    }
};