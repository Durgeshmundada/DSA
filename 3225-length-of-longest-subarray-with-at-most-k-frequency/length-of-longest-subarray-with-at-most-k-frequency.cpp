class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int count=0;
        int ans=0;
        int idx=0;
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
            if(um[nums[i]]<k){
                um[nums[i]]++;
                count++;
            }
            else{
                while(um[nums[i]]>=k){
                    um[nums[idx]]--;
                    count--;
                    idx++;
                }
                um[nums[i]]++;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};