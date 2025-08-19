class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
     long long max=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            max++;
        }
        else{
            if(max!=0){
            count=count+(max*(max+1))/2;
            max=0;}
        }
        if(max!=0 && i==nums.size()-1){
              count=count+(max*(max+1))/2;
        }
     }   
     return count;
    }
};