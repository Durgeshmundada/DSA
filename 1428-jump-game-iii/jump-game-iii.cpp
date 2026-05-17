class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),0);
        vector<int> dp1(arr.size(),-1);
        return canr(arr,start,dp,dp1);
    }
    bool canr(vector<int>& arr,int start,vector<int>& dp,vector<int>& dp1){
        if(dp1[start]!=-1) return dp1[start];
        if(dp[start]==1) return false;
        if(arr[start]==0) return true;
        dp[start]=1;
        return dp1[start]=(start-arr[start]>=0? canr(arr,start-arr[start],dp,dp1):false) || (start+arr[start]<arr.size()?canr(arr,start+arr[start],dp,dp1):false);
    }
};