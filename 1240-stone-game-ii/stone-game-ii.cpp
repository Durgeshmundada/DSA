class Solution {
public: 
vector<vector<int>> dp;
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<int>(n+1,-1));
        vector<int> sum(n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            sum[i] = sum[i + 1] + piles[i];
        }
        return check(piles,sum,0,1 );
    }

    int check(vector<int>& piles, vector<int>& sum, int idx, int x) {
        if (piles.size() - idx <= 2 * x) {
            return sum[idx];
        }
        
        if(dp[idx][x]!=-1) return dp[idx][x];
        int best = 0;

        for (int i = 1; i <= 2 * x; i++) {
            
            int other=check(piles,sum, idx + i, max(x, i));
            int current=sum[idx]-other;
            best=max(best,current);
        }

        return dp[idx][x]=best;
    }
};