class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result= nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int x=i+1;
            int y=nums.size()-1;
            while(x<y){
                int sum=nums[x]+nums[y]+nums[i];
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
                if(nums[x]+nums[y]+nums[i]>target){
                   y--;
                }
                else if(nums[x]+nums[y]+nums[i]<target){
                    x++;
                }
                else{
                    return target;
                }
             
            }
        }
        return result;
    }
};