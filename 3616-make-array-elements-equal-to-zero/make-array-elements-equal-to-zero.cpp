class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result=0;
        int sum=0;
        int sum1=0;
        for(int i =0;i<nums.size();i++){
          sum+=nums[i]; 
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int check=sum-sum1;
                if(check==sum1){
                    result+=2;
                }
               else if(check+1==sum1 || check==sum1+1){
                    result++;
                }    
            }else{
                    sum1+=nums[i];
                }
        }
        return result;
    }
};