class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];
        int mi=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mx,mi);
            }
            mx=max(nums[i],mx*nums[i]);
            mi=min(nums[i],mi*nums[i]);
            ans=max(ans,mx);
        }
        return ans;
    }
};