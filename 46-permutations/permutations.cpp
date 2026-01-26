class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        per(nums,arr);
        return result;
    }
    void per(vector<int>& nums,vector<int>& arr){
        if(nums.size()==0){
          result.push_back(arr);
          return;
        }
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
            vector<int> n=nums;
            n.erase(n.begin()+i);
            per(n,arr);
            arr.pop_back();
        }
        return;
    }
};