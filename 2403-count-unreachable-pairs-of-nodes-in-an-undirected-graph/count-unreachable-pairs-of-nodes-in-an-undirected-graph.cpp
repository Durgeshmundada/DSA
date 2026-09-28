class Solution {
public:
vector<int> result;
int find(int x){
    if(result[x]==x){
        return result[x];
    }
    return find(result[x]);
}
bool check(int a,int b){
    int x=find(a);
    int y=find(b);
    if(y==x) return true;
    return false;
}
void unio(int a,int b){
    int x=find(a);
    int y=find(b);
    result[y]=x;
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        result.resize(n);
        for(int i=0;i<n;i++){
            result[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            unio(edges[i][0],edges[i][1]);
        }
        unordered_map<int,int>um;
        
        for(int i=0;i<n;i++){
            int y=find(i);
            
          um[y]++;
                
        }
        long long ans=0;
        long long z=0;

        for(auto it:um){
            ans += it.second*z;
            z += it.second;
        }

        return ans;
    }
};