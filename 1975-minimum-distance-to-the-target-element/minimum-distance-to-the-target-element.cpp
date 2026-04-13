class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=0;
        int result=INT_MAX;
        while(i<nums.size()){
            if(nums[i]==target){
                result=min(abs(i-start),result);
            }
            i++;
        }
        
       
        return result;
    }
};