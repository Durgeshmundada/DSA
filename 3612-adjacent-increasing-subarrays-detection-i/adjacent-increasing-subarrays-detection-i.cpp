class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<=nums.size()-2*k;i++){
            int j=i+1;
            int v=k+i+1;
            while(j<i+k && nums[j]>nums[j-1] && nums[v]>nums[v-1]){
              j++;
              v++;
            }
            if(j==i+k){
                return true;
            }
        }
        return false;
    }
};