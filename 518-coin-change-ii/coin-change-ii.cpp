class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
       return coin(coins,0,amount,dp); 
    }
    int coin(vector<int>&list,int idx,int target, vector<vector<int>> &dp) {
        
        if(target==0)return 1;
        if(target<0 || idx>=list.size()) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take=coin(list,idx,target-list[idx], dp);
        int skip=coin(list,idx+1,target, dp);
        return dp[idx][target]=take+skip;
    }
};