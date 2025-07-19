class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int n=size-2;
        while(n>=0 && nums[n]>=nums[n+1]){
            n--;
        }
        int j=size-1;
        if(n>=0){
            while(nums[j]<=nums[n]){
                j--;
            }
            std::swap(nums[n],nums[j]);
        }

     std::reverse(nums.begin() + n + 1, nums.end());
        
        
    }
};