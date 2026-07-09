class Solution {
public:
vector<int> result;
    int find(int x){
        if(result[x]!=x) return find(result[x]);
        return result[x];
    }
    bool check(int x,int y){
        int r1=find(x);
        int r2=find(y);
        if(r1==r2) return true;
        return false;
    }
    void unio(int a,int b){
        int r1=find(a);
       int r2= find(b);
       if(r1==r2) return;
       result[r2]=r1;
       return;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        result.resize(n);
        for(int i=0;i<n;i++){
            result[i]=i;
        }
        for(int i=1;i<nums.size();i++){
              if(abs(nums[i-1]-nums[i])<=maxDiff) unio(i-1,i);
        }
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            if(check(queries[i][0],queries[i][1])) ans[i]=true;
        }
        return ans;
    }
};