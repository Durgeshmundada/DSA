class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
        }
        int result=0;
        int left=0;
        int right=count;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right-=nums[i];
            if((left-right)%2==0){
                result++;
            }
        }
        return result;
    }
};