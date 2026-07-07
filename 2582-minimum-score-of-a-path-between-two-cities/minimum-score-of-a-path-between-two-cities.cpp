class Solution {
public:
    vector<int> result;
    unordered_map<int,int>um;
    
   int find(int x){
        if(result[x]!=x){
            result[x]=find(result[x]);
        }
        return result[x];
    }
    bool check(int a, int b){
       int r1=find(a);
       int r2= find(b);
       if(r1==r2) return false;
       return true;
    }
    void unio(int a, int b){
        int r1=find(a);
       int r2= find(b);
       if(r1==r2) return;
       result[r2]=r1;
        if(um.find(r1)!=um.end() && um.find(r2)!=um.end())
            um[r1]=min(um[r1],um[r2]);
        else if(um.find(r2)!=um.end())
            um[r1]=um[r2];

        um.erase(r2);
       return; 
    }
    int minScore(int n, vector<vector<int>>& roads) {
        result.resize(n+1);
        for(int i=0;i<=n;i++){
            result[i]=i;
        }
        
        
         for(int i=0;i<roads.size();i++){

            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];

            if(check(u,v))
                unio(u,v);

            int root=find(u);

            if(um.find(root)==um.end())
                um[root]=w;
            else
                um[root]=min(um[root],w);
        }
        return um[find(n)];
    }
};