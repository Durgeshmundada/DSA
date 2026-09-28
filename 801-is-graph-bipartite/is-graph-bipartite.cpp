class Solution { 
public: 
    bool isBipartite(vector<vector<int>>& graph) { 
        vector<int>dp(graph.size(),-1); 
        
        for(int i=0;i<graph.size();i++){ 
            if(dp[i]==-1){
                dp[i]=0;

                if(!check(dp,graph,i,0)){ 
                    return false; 
                } 
            }
        } 
        return true; 
    } 

    bool check(vector<int>& dp,vector<vector<int>>& graph,int x,int color){ 
        
        for(int i=0;i<graph[x].size();i++){ 
            
            if(dp[graph[x][i]]==-1){
                dp[graph[x][i]]=(color+1)%2;

                if(!check(dp,graph,graph[x][i],(color+1)%2)){
                    return false;
                }
            }
            else if(dp[x]==dp[graph[x][i]]) {
                return false; 
            }
        } 
        
        return true; 
    } 
};