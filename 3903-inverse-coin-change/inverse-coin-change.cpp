class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        
        vector<int>list;
        for(int i=1;i<=numWays.size();i++){
            int waysChut=0;
            if(!list.empty()){
                vector<vector<int>> dp(list.size(), vector<int>(i+1, -1));
                waysChut = coin(list, 0, i, dp);
            }
            if(waysChut == numWays[i-1]) continue;

            list.push_back(i);
            vector<vector<int>> dp(list.size(), vector<int>(i+1, -1));
            int ways = coin(list, 0, i, dp);
            if(ways != numWays[i-1]) return {};       
        }
        return list;
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