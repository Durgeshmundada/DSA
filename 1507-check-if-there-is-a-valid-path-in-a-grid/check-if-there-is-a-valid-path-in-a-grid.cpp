class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unio(int a, int b) {
        int r1 = find(a);
        int r2 = find(b);
        if (r1 != r2)
            parent[r2] = r1;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n * m);

        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
        }

        // directions: left, right, up, down
        vector<vector<vector<int>>> dir = {
            {}, // 0 dummy
            {{0,-1},{0,1}},        // 1
            {{-1,0},{1,0}},        // 2
            {{0,-1},{1,0}},        // 3
            {{0,1},{1,0}},         // 4
            {{0,-1},{-1,0}},       // 5
            {{0,1},{-1,0}}         // 6
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int cur = i * m + j;

                for (auto d : dir[grid[i][j]]) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                        continue;

                    int next = ni * m + nj;

                    // check reverse connection
                    for (auto back : dir[grid[ni][nj]]) {
                        if (ni + back[0] == i && nj + back[1] == j) {
                            unio(cur, next);
                        }
                    }
                }
            }
        }

        return find(0) == find(n * m - 1);
    }
};