class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       if(nums.size()<3){
        return 0;
       }
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
         
          int y=i+1;
          int z=i+2;
          while(y<nums.size()-1){
            while (z < nums.size() && nums[i] + nums[y] > nums[z]) {
                    z++;
                }
                if (z > y) {
        count += (z - y - 1);
    }  y++;
          }
        
          
        }
        return count;
    }
    
};