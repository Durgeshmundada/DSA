class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        backtrack(0,nums,cur);
        return result;
    }
    void backtrack(int idx,vector<int>& nums,vector<int>& cur){
        result.push_back(cur);
        for(int i=idx;i<nums.size();i++){
            cur.push_back(nums[i]);
            backtrack(i+1,nums,cur);
            cur.pop_back();
        }
    }
};