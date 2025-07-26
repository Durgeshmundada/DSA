class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int s=nums.size();
        int y=1;
        if(s==0 || s==1 ){
            return false;
        }
      sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
              y=nums[i]^nums[i+1];
              if(y==0){
                return true;
              }
              }
       
            return false;
        
        
    }
};