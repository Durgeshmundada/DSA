class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if (i >0 && nums[i] == nums[i - 1]) continue;
        for(int j=i+1;j<nums.size()-2;j++){
            if (j > i+1 && nums[j] == nums[j - 1]) continue;
            int left=j+1;
            int right=nums.size()-1;
            

            while(left<right){
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if(sum > target){
                    right--;
                }
                else if(sum< target){
                    left++;
                }
                else{
                   
                            result.push_back({nums[i],nums[j],nums[left],nums[right]});
                            int last_left = nums[left], last_right = nums[right];
                           while (left < right && nums[left] == last_left ) left++;
                           while (left < right && nums[right] ==last_right ) right--;
                        
                        
                        
                }
            }
            }
        }
        return result; 
    }
};