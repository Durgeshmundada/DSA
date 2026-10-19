class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<int>res;
        while(i<nums.size() && nums[i]!=target){
            i++;
        }
        while(i<nums.size() && nums[i]==target){
            res.push_back(i);
            i++;
        }
        return res;
    }
};