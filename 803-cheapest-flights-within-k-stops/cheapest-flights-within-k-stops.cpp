class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<int> temp(n,1e8);
        temp[src]=0;
        
        for(int i=0;i<k+1;i++){
            vector<int>dist=temp;
            for(auto it:flights){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(temp[u]!=1e8 && temp[u]+wt<dist[v]){
                    dist[v]=temp[u]+wt;
                }
                
            }
            temp=dist;
        }
        if(temp[dst] == 1e8)
            return -1;
       return temp[dst] ;
    }
};