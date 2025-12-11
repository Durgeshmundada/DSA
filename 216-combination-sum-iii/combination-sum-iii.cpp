class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
         vector<vector<int>> ans;
        vector<int> temp;
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        sort(candidates.begin(),candidates.end());
        solve(0, target, candidates, temp, ans,k);
        return ans;
    }
     void solve(int idx,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans,int k){
        if (target == 0) {
            if(temp.size()==k){
            ans.push_back(temp);}
            return;
        }
         if ( idx == candidates.size() || target < 0) {
            return;
        }
        for(int i=idx;i<candidates.size();i++){
             if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(i+1, target-candidates[i], candidates, temp, ans,k);
            temp.pop_back();
        }
        return;
    }
};