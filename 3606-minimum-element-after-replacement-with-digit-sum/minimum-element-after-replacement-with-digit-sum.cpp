class Solution {
public:
    int minElement(vector<int>& nums) {
      int result=INT_MAX;
      for(int i=0;i<nums.size();i++){
        int x=nums[i];
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        result=min(result,sum);
      }
      return result;
    }
};