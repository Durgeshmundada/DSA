class DSU {
public:
    DSU(int n) : parent(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;
        // union by size
        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return true;
    }

private:
    vector<int> parent;
    vector<int> sz;
};
class Solution {
public:
bool check(int n, vector<vector<int>>& edges, int k, int mid) {

    DSU dsu(n);
    vector<pair<int,int>> upgrade;

    for(auto &edge : edges){
        int u=edge[0], v=edge[1], s=edge[2], m=edge[3];

        if(m==1){
            if(s < mid) return false;
            dsu.unite(u,v);
        }
        else{
            if(s >= mid){
                dsu.unite(u,v);
            }
            else if(2*s >= mid){
                upgrade.push_back({u,v});
            }
        }
    }

    for(auto &e : upgrade){
        int u=e.first, v=e.second;

        if(dsu.find(u) != dsu.find(v)){
            if(k == 0) return false;
            dsu.unite(u,v);
            k--;
        }
    }

    int root = dsu.find(0);
    for(int i=1;i<n;i++){
        if(dsu.find(i) != root) return false;
    }

    return true;
}
    int maxStability(int n, vector<vector<int>>& edges, int k) {

    DSU dsu(n);

    for(auto &edge:edges){
        int u=edge[0], v=edge[1], m=edge[3];

        if(m==1){
            if(dsu.find(u)==dsu.find(v))
                return -1;
            dsu.unite(u,v);
        }
    }

    int result=-1;
    int l=1;
    int r=2e5;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(check(n,edges,k,mid)){
            result=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return result;
}
};