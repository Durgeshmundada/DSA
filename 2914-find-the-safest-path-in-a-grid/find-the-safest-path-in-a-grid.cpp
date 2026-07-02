class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    safe[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int p1[]={-1,1,0,0};
        int p2[]={0,0,-1,1};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int r=curr.first;
            int s=curr.second;
            for(int k=0;k<4;k++){
                int r1=r+p1[k];
                int s1=s+p2[k];
                if(r1>=0 && r1<n && s1>=0 && s1<n && safe[r1][s1]==-1){
                    safe[r1][s1]=safe[r][s]+1;
                    q.push({r1,s1});
                }
            }
        }
        priority_queue<vector<int>> pq;
        pq.push({safe[0][0],0,0});
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int val=curr[0];
            int r=curr[1];
            int s=curr[2];
            if(visit[r][s]) continue;
            if(r==n-1 && s==n-1) return val;
            visit[r][s]=true;
            for(int k=0;k<4;k++){
                int r1=r+p1[k];
                int s1=s+p2[k];
                if(r1>=0 && r1<n && s1>=0 && s1<n && !visit[r1][s1]){
                    pq.push({min(val,safe[r1][s1]),r1,s1});
                }
            }
        }
       return 0;
    }
    
};








