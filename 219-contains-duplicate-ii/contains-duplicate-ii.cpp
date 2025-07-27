class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int s=nums.size();
        int y=1;
        if(s==0 || s==1 ){
            return false;
        }
      
        for(int i=0;i<nums.size();i++){
              for( int j=i+1;j<=i+k &&  j<(nums.size());j++ ){
                y=nums[i]^nums[j];
                if(y==0 ){
                    return true;
                }
              }
             
        }
        
        
            return false;   
    }
};