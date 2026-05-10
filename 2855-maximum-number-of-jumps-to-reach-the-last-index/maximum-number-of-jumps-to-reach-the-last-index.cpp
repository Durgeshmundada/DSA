class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-2);
        return maxd(nums,target,0,dp);
    }
    int maxd(vector<int>& nums,int target, int index,vector<int>& dp){
        if(index==nums.size()-1){
            return 0;
        }
        int result=-1;
        if(dp[index]!=-2){
            return dp[index];
        }
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]-nums[index]<=target && nums[i]-nums[index]>=(0-target)){
                 int temp = maxd(nums, target, i, dp);

                if(temp != -1) {
                    result = max(result, 1 + temp);
                }
            }
            
        }
        return dp[index]=result;
    }
};