class Solution {
public:
    bool canJump(vector<int>& nums) {
       vector<int> dp(nums.size(),-1);
       return canj(nums,dp,0); 
    }
    bool canj(vector<int>& nums,vector<int>& dp,int idx){
        if(idx==nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx+1;i<=idx+nums[idx];i++){
            if(canj(nums,dp,i)) return true;
        }
        return dp[idx]=false;
    }
};