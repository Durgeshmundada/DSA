class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first=0;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[first]!=nums[i]){
                nums[first+1]=nums[i];
                first++;
            }
        }
        return first+1;
    }
};