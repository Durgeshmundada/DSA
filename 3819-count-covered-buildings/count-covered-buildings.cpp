class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int,int> xr,yr,xl,yl;
        for(auto i:b){
            xr[i[0]]++;
            yr[i[1]]++;
        }
        sort(b.begin(),b.end());
        int count=0;
        for(int i=0;i<b.size();i++){
            xr[b[i][0]]--;
            yr[b[i][1]]--;
              if(xl[b[i][0]]>0 && yl[b[i][1]]>0 && xr[b[i][0]]>0&& yr[b[i][1]]>0){
                count++;
              }
           xl[b[i][0]]++;
            yl[b[i][1]]++;
        }
        return count;  
    }
};