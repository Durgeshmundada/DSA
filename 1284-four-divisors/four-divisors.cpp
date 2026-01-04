class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=1+nums[i];
            int c=1;
            for(int j=2;j<nums[i];j++){
                if(nums[i]%j==0){
                    c++;
                    sum+=j;
                }
                if(c==4){
                    sum=0;
                    break;
                }
            }
             if(c<3){
                    sum=0;
                }
            count+=sum;
        }
        return count;
    }
};