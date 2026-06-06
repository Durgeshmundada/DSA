class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       int left=0;
       int right=0;
       vector<int> result(nums.size());
       for(int i=nums.size()-1;i>=0;i--){
        result[i]=right;
        right+=nums[i];
       } 
       for(int i=0;i<nums.size();i++){
        result[i]=abs(result[i]-left);
        left+=nums[i];
       } 
       return result;
    }
};