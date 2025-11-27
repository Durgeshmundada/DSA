class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int check=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
               if(check>0){
                return false;
               }
               check=k;
            }
            else{
                check--;
            }
        }
        return true;
    }
};