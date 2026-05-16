class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        while(high>low){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else if(nums[mid]<nums[low]) high=mid;
            else high--;
        }
        return nums[low];
    }
};