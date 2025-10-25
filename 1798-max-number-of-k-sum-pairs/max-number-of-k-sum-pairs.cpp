class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int result=0;
      sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        while(left<right){
           
            if(nums[right]+nums[left]==k){
                result++;
                left++;
                right--;
                
            }
            else if(nums[right]+nums[left]>k){
                right--;
            }
            else{
                left++;
            }
        }
        
      
      return result; 
    }
};