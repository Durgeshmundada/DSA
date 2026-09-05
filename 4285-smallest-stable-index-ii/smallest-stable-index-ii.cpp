class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mi(nums.size());
      mi[nums.size()-1]=nums[nums.size()-1];
      vector<int>ma(nums.size());
      ma[0]=nums[0];
      for(int i=1;i<nums.size();i++){
        if(nums[i]>ma[i-1]){
            ma[i]=nums[i];
        }
        else ma[i]=ma[i-1];
        if(nums[nums.size()-i-1]<mi[nums.size()-i]) mi[nums.size()-i-1]=nums[nums.size()-i-1];
        else mi[nums.size()-i-1]=mi[nums.size()-i];
      }
      int ans=INT_MAX;
      for (int i = 0; i < nums.size(); i++) {
            if (ma[i] - mi[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};