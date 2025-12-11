class Solution {
public:
    int combinationSum4(vector<int>& candidates, int target) {
        vector<int> prex(target+1,-1);
        return solve(candidates,target,prex);
    }
    int solve(vector<int>& candidates, int target,vector<int>& prex){
        if (target == 0) {
            return 1;
        }
         if (target < 0) {
            return 0;
        }
        if(prex[target]!=-1){
            return prex[target];
        }
        int sum=0;
        for(int i=0;i<candidates.size();i++){  
           sum+= solve( candidates,target-candidates[i],prex);
        }
        prex[target]=sum;
        return sum;
    }
};