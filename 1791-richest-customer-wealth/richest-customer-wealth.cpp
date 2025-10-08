class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int max1=0;
       for(int i=0;i<accounts.size();i++){
        int x=0;
        for(int j=0;j<accounts[i].size();j++){
            x+=accounts[i][j];
        }max1=max(max1,x);
       } 
       return max1;
    }
};