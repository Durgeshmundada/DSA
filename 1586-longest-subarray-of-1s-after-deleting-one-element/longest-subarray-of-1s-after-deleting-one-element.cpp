class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int max1=0;
        int sum=0;
        int f=0;
        bool usedZero = false;
        for(int i=0;i<nums.size();i++){
            
             if(nums[i]==1){
                
                max1++;
            }
            else {

                if(!usedZero ){
                    usedZero=true;
                    sum=max1;
                    max1=0;
                }
                else{
                    f=max(f,sum+max1);
                    sum=max1;
                    max1=0;

                }
            }
           
        }
        
           f=max(f,sum+max1); 
        
        if(f==nums.size()){
            return nums.size()-1;
        }
            return f;
    }
};