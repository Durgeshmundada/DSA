class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count =0;
        int check=0;
        for(int i=0;i<nums.size();i++){
           
            if(nums[i]==1){
                count++;
           }
        }
        if(count>0){
            return nums.size()-count;
        }
        int minlen=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            for(int j=i+1;j<nums.size();j++){
                curr=gcd(curr,nums[j]);
                if(curr==1){
                    minlen=min(minlen,j-i+1);
                    break;
                }
            }
        }
        if(minlen==INT_MAX){
            return -1;
        }
        return  (nums.size()-1)+(minlen-1);
    }
};