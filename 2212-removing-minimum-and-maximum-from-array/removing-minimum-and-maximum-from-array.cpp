class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int posmin=0;
        int posmax=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[posmax]){
                posmax=i;
            }
            if(nums[i]<nums[posmin]){
                posmin=i;
            }
        }
        
        int ans=max(posmax,posmin)+1; 
        ans=min(ans,(int)(nums.size()-(min(posmax,posmin))));
        ans=min(ans,(int)(nums.size()-(max(posmax,posmin))+min(posmax,posmin)+1));
        return ans;

    }
};