class Solution {
public:
vector<int> res;
int find(int x){
    if(res[x]==x){
        return x;
    }
    return find(res[x]);
}
bool check(int a, int b){
    int x=find(a);
    int y=find(b);
    if(a==b) return true;
    return false;
}
void unio(int a, int b){
        int r1=find(a);
       int r2= find(b);
       if(r1==r2) return;
       res[r2]=r1;
       return; 
    }
   
    int findCircleNum(vector<vector<int>>& isConnected) {
        res.resize(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            res[i]=i;
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    unio(i,j);
                }
            }
        }
        int ans=0;
        unordered_map<int,int>um;
        for(int i=0;i<isConnected.size();i++){
            um[find(i)]=1;
        }
        for(auto x:um){
            ans++;
        }
        return ans;
    }
};