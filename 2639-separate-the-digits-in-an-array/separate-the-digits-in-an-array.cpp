class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
      vector<int> result;
      for(int i=nums.size()-1;i>-1;i--){
        while(nums[i]!=0){
            result.insert(result.begin(),nums[i]%10);
            nums[i]/=10;
        }
      }  
      return result;
    }
};