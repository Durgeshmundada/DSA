class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
     return rec(nums,target,0,0);
    }
    int rec(vector<int>& nums, int target,int x,int sum){
        if (x == nums.size()) {
            return sum == target ? 1 : 0;
        }
        int add=rec(nums,target,x+1,sum+nums[x]);
        int sub=rec(nums,target,x+1,sum-nums[x]);
        return add+sub;
    }
};