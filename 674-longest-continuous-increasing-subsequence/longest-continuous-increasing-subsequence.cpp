class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
       int y=1;
       int count=1;
       for(int i=1;i<nums.size();i++){
         if(nums[i]>nums[i-1]){
            count++;
         }
         else{
            if(y<count){
                y=count;
            }
            count=1;
          }

       }
       
       return max(y,count);
    }
};