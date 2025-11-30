class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long target=0;   
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        target=target%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int> um;
        um[0]=-1;
       long long prefix=0;
       int res=nums.size();
       for(int i=0;i<nums.size();i++){
        prefix=(prefix+nums[i])%p;
        int want=(prefix-target+p)%p;
        if(um.count(want)){
            res=min(res,i-um[want]);
        }
        um[prefix]=i;
       }
       return res==nums.size()?-1:res;
    }
};