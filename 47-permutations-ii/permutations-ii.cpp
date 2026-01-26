class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> um;
        vector<int>curr=nums;
         vector<vector<int>> v;
         func(v,nums,curr,0);
         return v;
    }
    void func(vector<vector<int>>& v,vector<int>& nums,vector<int>&curr,int i){
        int n=nums.size();
        if(i==n){
            v.push_back(curr);
            return;
        }
        unordered_set<int> um;
        for(int j=i;j<n;j++){
             if (um.count(curr[j])) continue;
             um.insert(curr[j]);
            swap(curr[i],curr[j]);
            func(v,nums,curr,i+1);
            swap(curr[i],curr[j]);
        }

    }
};