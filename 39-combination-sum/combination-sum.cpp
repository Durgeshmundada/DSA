class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, candidates, temp, ans);
        return ans;
    }
     void solve(int idx,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans){
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
         if (idx == candidates.size() || target < 0) {
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(i, target-candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
        return;
    }
};