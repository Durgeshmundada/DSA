class Solution {
public:
vector<int> result; 
   int find(int x){
        if(result[x]!=x){
            result[x]=find(result[x]);
        }
        return result[x];
    }
    bool check(int a, int b){
       int r1=find(a);
       int r2= find(b);
       if(r1==r2) return true;
       return false;
    }
    void unio(int a, int b){
        int r1=find(a);
       int r2= find(b);
       if(r1==r2) return;
       result[r2]=r1;
       return; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        result.resize(edges.size()+1);
        for(int i=0;i<edges.size()+1;i++){
            result[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            if(check(edges[i][0],edges[i][1])){
                return {edges[i][0],edges[i][1]};
            }
            unio(edges[i][0],edges[i][1]);
        }
        return {};
    }
};