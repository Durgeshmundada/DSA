class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         int count=0;
       vector<vector<int>> twoDVector;
        
        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);
             for (int j = 1; j < i; ++j) {
                row[j] = twoDVector[i - 1][j - 1] + twoDVector[i - 1][j];
            }

            twoDVector.push_back(row);
        }
        
        return twoDVector;
    }
};