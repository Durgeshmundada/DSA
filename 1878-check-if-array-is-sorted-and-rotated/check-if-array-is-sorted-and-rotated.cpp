class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        int check =INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(flag>1) return false;
            if(flag==1){
                if(nums[i]>check) return false;
                if(nums[i]>nums[(i+1)%nums.size()]){
                return false;
            }
            }
        else{
            if(nums[i]>nums[(i+1)%nums.size()]){
                flag++;
            }
            else{
                check=min(check,nums[i]);
            }}
        }
        return true;
    }
};