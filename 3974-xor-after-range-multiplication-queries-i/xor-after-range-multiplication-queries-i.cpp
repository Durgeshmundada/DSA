class Solution {
public:const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            while(idx<=r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx+=k;
            }
        }
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            result=result^nums[i];
        }
        return result;
    }
};