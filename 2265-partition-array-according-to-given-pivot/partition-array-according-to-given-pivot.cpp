class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int x=0;
       int y=0;
       vector<int> v;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot){
           v.insert(v.begin()+x, nums[i]);
           x++;
        }
        else if(nums[i]==pivot){
            v.insert(v.begin()+x, nums[i]);
        }
        else{
            v.push_back(nums[i]);
        }
       }
       return v;
    }
};