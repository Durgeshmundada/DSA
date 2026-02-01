class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int result=nums[0];
        sort(nums.begin()+1,nums.end());
        return result+nums[1]+nums[2];
    }
};