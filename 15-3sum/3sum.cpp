class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> um;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0){
                return result;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    vector<int> result1={nums[i],nums[left],nums[right]};
                    if (um.find(result1) == um.end()) {
                            result.push_back(result1);
                            um.insert(result1);
                        }
                        left++;
                }
            }
        }
        return result;
    }
};