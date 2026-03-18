class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=-1;
        int end=-1;
        int i=0;
        while(i < nums.size()-1 && nums[i] <= nums[i+1]) i++;
        if(i==nums.size()-1) return 0;
        start=i;
        i=nums.size()-1;
        while(i>0&&nums[i]>=nums[i-1]) i--;
        end=i;
        int maxa=INT_MIN;
        int mini=INT_MAX;
        for(int i=start;i<=end;i++){
            maxa=max(maxa,nums[i]);
            mini=min(mini,nums[i]);
        }
        i=0;
        while(i < start && nums[i] <= mini) i++;
        start=i;

        i=n-1;
        while(i > end && nums[i] >= maxa) i--;
        end=i;

        return end-start+1;
    }
};