class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count=1;
       int num=nums[0];
       int n=nums.size();
       for(int i=1;i<n;i++){
          if(num==nums[i]){
            count++;
            if(count>2){
                nums.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                n--;
                i--;
            }
          }
          else{
            num=nums[i];
            count=1;
          }
          
       } 
       return n;
    }
};