class Solution {
public:
    vector<int> result;

    int find(int x){
        if(result[x] != x){
            result[x] = find(result[x]);
        }
        return result[x];
    }

    void unio(int a, int b){
        int r1 = find(a);
        int r2 = find(b);
        if(r1 != r2){
            result[r2] = r1;
        }
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // init DSU
        result.resize(n);
        for(int i = 0; i < n; i++) result[i] = i;

        // 🔴 Step 1: basic validation
        for(int i = 0; i < n; i++){
            if(lcp[i][i] != n - i) return "";
            for(int j = 0; j < n; j++){
                if(lcp[i][j] != lcp[j][i]) return "";
                if(lcp[i][j] > n - max(i, j)) return "";
            }
        }

        // 🔴 Step 2: LCP recurrence validation (CRITICAL FIX)
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i < n-1 && j < n-1 && lcp[i][j] > 0){
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]){
                        return "";
                    }
                }
            }
        }

        // 🔴 Step 3: union based on lcp > 0
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(lcp[i][j] > 0){
                    unio(i, j);
                }
            }
        }

        // 🔴 Step 4: build lexicographically smallest string
        string res(n, '?');
        char ch = 'a';

        for(int i = 0; i < n; i++){
            if(find(i) == i){
                if(ch > 'z') return "";
                res[i] = ch++;
            }
        }

        for(int i = 0; i < n; i++){
            res[i] = res[find(i)];
        }

        // 🔴 Step 5: final strict validation (break condition)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = lcp[i][j];
                if(i + k < n && j + k < n){
                    if(res[i+k] == res[j+k]){
                        return "";
                    }
                }
            }
        }

        return res;
    }
};