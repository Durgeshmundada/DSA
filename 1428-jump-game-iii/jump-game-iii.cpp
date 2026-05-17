class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),0);
        return canr(arr,start,dp);
    }
    bool canr(vector<int>& arr,int start,vector<int>& dp){
        if(dp[start]==1) return false;
        if(arr[start]==0) return true;
        dp[start]=1;
        return (start-arr[start]>=0? canr(arr,start-arr[start],dp):false) || (start+arr[start]<arr.size()?canr(arr,start+arr[start],dp):false);
    }
};