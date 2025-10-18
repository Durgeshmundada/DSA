class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if (nums.empty()) return 0; 
        sort(nums.begin(),nums.end());
        nums[0]=nums[0]-k;
        for(int i=1;i<nums.size();i++){
            int first=nums[i]-k;
            int last=nums[i]+k;
            if(nums[i-1]<nums[i]-k){
                nums[i]=nums[i]-k;
            }
            else{
                
                    int delta = min(nums[i-1] + 1 - nums[i], k);
                    nums[i] = nums[i] + delta;
                
            }
        }
        int result=0;
         sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                result++;
            }
        }
        return result+1;
    }
};