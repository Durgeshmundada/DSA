class Solution {
public:
 vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    bool check(int a, int b) {
        return find(a) != find(b);
    }

    void unio(int a, int b) {
        int r1 = find(a);
        int r2 = find(b);
        if (r1 != r2) {
            parent[r2] = r1;
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n * m);

        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
        }
        vector<pair<int,int>> p={{0,1},{1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto x:p){
                    int i1=i+x.first;
                    int i2=j+x.second;
                    if(i1<n&&i2<m&&grid[i1][i2]==grid[i][j]){
                        int m1=i*m+j;
                        int m2=i1*m+i2;
                        if(find(m1)==find(m2)) return true;
                        unio(m1,m2);
                    }
                }
            }
        }
        return false;
    }
};