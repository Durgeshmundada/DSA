class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int>um;
        unordered_map<int,int>um1;
        unordered_map<int,int>um2;
        int result=INT_MAX;
        for(int i= nums.size()-1;i>=0;i--){
            
            if(um.find(nums[i])==um.end()) um[nums[i]]=i;
            else if(um1.find(nums[i])==um1.end()) um1[nums[i]]=i;
            else if(um2.find(nums[i])==um2.end()) {
                um2[nums[i]]=i;
                int dis=abs(um[nums[i]]-um1[nums[i]])+abs(um1[nums[i]]-um2[nums[i]])+abs(um[nums[i]]-um2[nums[i]]);
                result=min(result,dis);
        }
        else {
                
                um[nums[i]] = um1[nums[i]];
                um1[nums[i]] = um2[nums[i]];
                um2[nums[i]] = i;

                int dis = abs(um[nums[i]] - um1[nums[i]]) +
                          abs(um1[nums[i]] - um2[nums[i]]) +
                          abs(um[nums[i]] - um2[nums[i]]);

                result = min(result, dis);
            }
        }
        if(result==INT_MAX) return -1;
        return result;
    }
};