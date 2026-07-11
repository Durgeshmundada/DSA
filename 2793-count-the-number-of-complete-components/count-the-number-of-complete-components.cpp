class Solution {
public:
vector<vector<int>> result;
vector<int>comp;
void unio(int a,int b){
    result[a].push_back(b);
    result[b].push_back(a);
    return;
}
void dfs(int a,vector<bool>& check){
    check[a]=true;
    comp.push_back(a);
    for(int x: result[a]){
        if(!check[x])
         dfs(x,check);
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        result.resize(n);
       
        for(int i=0;i<edges.size();i++){
            unio(edges[i][0],edges[i][1]);
        }
        vector<bool>check(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!check[i]){
                comp.clear();
                dfs(i,check);
                int ds=comp.size();
                bool temp=true;
                for(int node:comp){
                    if (result[node].size() != ds - 1) {
                        temp = false;
                        break;
                    }
                    
                }
                if(temp){
                        ans++;
                    }
            }
        }
        return ans;
    }
};